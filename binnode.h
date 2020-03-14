#ifndef BINNODE_H
#define BINNODE_H
#include <iostream>
using namespace std;

template <typename E>

class BSTNode
{
private:
    E element;
    BSTNode<E> *left;
    BSTNode<E> *right;

public:
    BSTNode(E element, BSTNode<E>*left=NULL,BSTNode<E>*right=NULL) {
        this->element=element;
        this->left=left;
        this->right=right;

    }
    ~BSTNode(){

    }

    E getElement(){
        return element;
    }

    void setElement(E element){
        this->element;
    }

    BSTNode<E> *getLeft(){
            return left;
        }

        void setLeft(BSTNode<E> *left){
            this->left = left;
        }

        BSTNode<E> *getRight(){
            return right;
        }

        void setRight(BSTNode<E> *right){
            this->right = right;
        }

        bool isLeaf(){
            return left==NULL && right==NULL;
        }

        int childrenCount(){
            return(left==NULL?0:1)+(right==NULL?0:1);
        }

        BSTNode<E> *getUniqueChild(){
            return left==NULL ? right : left;
        }

        BSTNode<E> * getSuccesor(){
            return getSuccessorAux(right);
        }

private:
        BSTNode<E> *getSuccessorAux(BSTNode<E> *pRoot){
            if(pRoot==NULL)return NULL;
            if(pRoot->left==NULL)return pRoot;
            else{
                return getSuccessorAux(pRoot->left);
            }
        }

private:
        void swap(BSTNode<E>*node1,BSTNode<E>*node2){
            E temp= node1->getElement();
            node1->setElement(node2->getElement());
            node2->setElement(temp);
        }
public:
        bool contains(E element){
            try {
                find(element);
                return true;
            } catch (runtime_error &e) {
                return false;

            }
        }

    void printer(){
        cout<<"HOLA";
    }

};
#endif // BINNODE_H
