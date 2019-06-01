#ifndef TRIE_H
#define TRIE_H
#include <string>
#include "trienode.h"
#include <stdexcept>
#include <iostream>
#include <cstring>

using namespace std;

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode();
    }

    ~Trie(){
        //clear();
        delete root;
    }

    bool containsWord(string word ){
        TrieNode *current=root;
        for (int i=0;i<word.size();i++) {
            char c=word[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return current->getIsFinal();
    }

    bool containsPrefix(string prefix){
        TrieNode *current=root;
        for (int i=0;i<prefix.size();i++) {
            char c=prefix[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return true;
    }

    int prefixCount(string prefix){
        TrieNode * current=root;
        for(unsigned int i=0; i<prefix.size();i++){
            if(!current->contains(prefix[i]))return 0;
            current=current->getChild(prefix[i]);
        }
        return current->getPrefixCount();
    }

    void remove(string word)throw (runtime_error){
        if (!containsWord(word))throw runtime_error("Word not Found");
        TrieNode *current=root;
        for(unsigned int i=0; i<word.size();i++){
            current->decreaseCount();
            TrieNode*child=current->getChild(word[i]);
            if(current->getPrefixCount()==0)delete current;
            if(child->getPrefixCount()==1)current->remove(word[i]);
            current=child;
        }
        current->decreaseCount();
        if(current->getPrefixCount()==0)delete current;
        else current->setIsFinal(false);
    }


public:

    void clear(){
        clearAux(root);
        root=new TrieNode();
    }

private:
    void clearAux(TrieNode *current){
        List<TrieNode*> *pointers= current->getChildrenPointers();
        for(pointers.goToStart();!pointers.atEnd();pointers.next()){
            clearAux(pointers.getElement());
        }
        delete current;
        delete pointers;
    }


public:
    List<string> *getMatches(string prefix){
        List<string>*words = new DlinkedList<string>();
        getMatchesAux(root,prefix"",words);
        return words;
    }

private:
    void getMatchesAux(TrieNode *current, string rest,string prefix,List<string>*words){
        if(current->getIsFinal())words.append(prefix);
        List<char>*children=current->getChildren();
        for(children->goToStart();!children->atEnd();children->next){
            char c=children->getElement();
            if(rest.size()==0){
                string newPrefix=prefix;
                newPrefix.append(1,c);
                getMatchesAux(current->getChild(c),rest,newPrefix,words);
            }


        }
        else if(c==rest[0]){
            string newPrefix = prefix;
            newPrefix.append(1,c);
            rest.erase(0,1);
            getMatchesAux(current->getChild(c),rest,newPrefix,words);
        }
        delete children;

    }











};



#endif // TRIE_H
