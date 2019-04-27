#ifndef TRIE_H
#define TRIE_H
#include "trienode.h"
#include <string>
#include <stdexcept>

using namespace std;

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode();
    }

    ~Trie(){
        clear();
        delete root;
    }

    bool containsWord(string word){
        TrieNode *current=root;
        for (int i=0;i<word.size();i++) {
            char c=word[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return current->isFinal();
    }

    bool containsPrefix(string prefix){
        TrieNode *current=root;
        for (int i=0;i<word.size();i++) {
            char c=word[i];
            if(!current->contains(c)){
                return false;
            }
            current=current->getChild(c);
        }
        return true;
    }


};



#endif // TRIE_H
