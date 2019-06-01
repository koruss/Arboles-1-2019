#ifndef AVLTREE_H
#define AVLTREE_H
#include "binnode.h"

template <typename E>

class AVLTree
{

private:
    BSTNode<E> *root;
public:
    AVLTree(){
        root =NULL;
    }

    ~AVLTree(){
       // clear();
    }

    void insert(E element){
        root= insertAux(root,element);
    }

private:
    BSTNode<E> *rotateRight(BSTNode<E> *pRoot){
        if(pRoot==NULL) throw runtime_error("Cant rotate right on NULL");
        if(pRoot->getLeft()==NULL) throw runtime_error("Can't rotate right with NULL Left child");
        BSTNode<E> *temp=pRoot->getLeft();
        pRoot->setLeft(temp->getRight());
        temp->setRight(pRoot);
        return temp;

    }

    BSTNode<E> *rotateLeft(BSTNode<E> *pRoot){
        if(pRoot==NULL) throw runtime_error("Cant rotate left on NULL");
        if(pRoot->getRight()==NULL) throw runtime_error("Can't rotate left with NULL right child");
        BSTNode<E> *temp=pRoot->getRight();
        pRoot->setRight(temp->getLeft());
        temp->setLeft(pRoot);
        return temp;

    }


    int height(BSTNode<E> *pRoot){
        if(pRoot==NULL)return 0;
        int leftHeight =height(pRoot->getLeft());
        int rightHeight =height(pRoot->getRight());
        if(leftHeight>rightHeight)return leftHeight+1;
        else
            return rightHeight+1;
    }



private:
    BSTNode<E> *insertAux(BSTNode<E> *pRoot,E element){
        if(pRoot==NULL)return new BSTNode<E>(element);
        if(element==pRoot->getElement())throw runtime_error("Duplicated element");
        if(element<pRoot->getElement()){
            pRoot->setLeft(insertAux(pRoot->getLeft(),element));
            return rebalanceLeft(pRoot->getLeft());
        }
        else {
            pRoot->setRight(insertAux(pRoot->getRight(),element));
            return rebalanceRight(pRoot->getRight());
        }
    }


    BSTNode<E> * rebalanceLeft(BSTNode<E> *pRoot){
        int leftHeight=height(pRoot->getLeft());
        int rightHeight=height(pRoot->getRight());
        if(leftHeight-rightHeight>1){
            int leftleftHeight=height(pRoot->getLeft()->getLeft());
            int leftrightHeight =height(pRoot->getLeft()->getRight());
            if(leftleftHeight>=leftrightHeight){
                return rotateRight(pRoot);

            }
        }
        return pRoot;
    }

    BSTNode<E> * rebalanceRight(BSTNode<E> *pRoot){
       int leftHeight=height(pRoot->getLeft());
        int rightHeight=height(pRoot->getRight());
        if(rightHeight-leftHeight>1){
            int leftleftHeight=height(pRoot->getLeft()->getLeft());
            int leftrightHeight =height(pRoot->getLeft()->getRight());
            if(leftrightHeight>=leftleftHeight){
                return rotateLeft(pRoot);

            }
        }
    }

public:
    E remove(E element){
        E result=find(element);
        root=removeAux(root,element);
        return result;
    }

    BSTNode<E> *removeAux(BSTNode<E> *pRoot, E element){
        if(pRoot==NULL){throw runtime_error("Element not found");}
        if(element<pRoot->getElement()){
            pRoot->setLeft(removeAux(pRoot->getLeft(),element));
            pRoot = rebalanceRight(pRoot);
            return pRoot;
    }
        else if (element>pRoot->getElement()) {
            pRoot->setRight(removeAux(pRoot->getRight(),element));
            pRoot=rebalanceLeft(pRoot);
            return pRoot;
        }
        else{
            if(pRoot->isLeaf()){
                delete pRoot;
                return NULL;

            }
            if(pRoot->childrenCount()==1){
                BSTNode<E>*temp=pRoot->getUniqueChild();
                delete pRoot;
                return temp;
            }
        }

    }

public:

    void print(){
        printAux(root);
    }
    void printAux(BSTNode<E> *pRoot){
        if(pRoot==NULL){return;}
        printAux(pRoot->getLeft());
        cout<<pRoot->getElement();
        printAux(pRoot->getRight());


    }





};

#endif // AVLTREE_H
