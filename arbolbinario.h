#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "binnode.h"

template<typename E>

class BSTree{
private:
   BSTNode<E> *root;



public:
   BSTree(){
       root =NULL;
   }

   ~BSTree(){
      // clear();
   }

   void insert(E element){
       root= insertAux(root,element);

   }
private:
   BSTNode<E> *insertAux(BSTNode<E> *pRoot, E element){
       if(pRoot==NULL){
           return new BSTNode<E>(element);
       }

       if(element<pRoot->getElement()){
           pRoot->setLeft(insertAux(pRoot->getLeft(),element));
           return pRoot;
       }
       else{
           pRoot->setRight(insertAux(pRoot->getRight(),element));
           return pRoot;
       }
   }




public:
   E find(E element)throw(runtime_error){
       return findAux(root,element);
   }


private:
   E findAux(BSTNode<E>*pRoot,E element)throw(runtime_error){
       if(pRoot==NULL)throw runtime_error("Bla bla");
       if(element==pRoot->getElement())return pRoot->getElement();
       if(element<pRoot->getElement())return findAux(pRoot->getLeft(),element);
       else{
           return findAux(pRoot->getRight(),element);
       }
   }

public:
   E remove(E element)throw(runtime_error){
       E result = find(element);
       root =removeAux(root,element);
       return result;
   }

private:
   BSTNode<E> *removeAux(BSTNode<E> *pRoot, E element)throw(runtime_error){
       if(pRoot==NULL)throw runtime_error("Element not found");
       if(element<pRoot->getElement()){
           pRoot->setLeft(removeAux(pRoot->getLeft(),element));
           return pRoot;
       }
       if(element>pRoot->getElement()){
           pRoot->setRight(removeAux(pRoot->getRight(),element));
           return pRoot;
       }
       else{
           if(pRoot->isLeaf()){
               delete pRoot;
               return NULL;
           }
           if(pRoot->childrenCount()==1){
               BSTNode<E> *temp = pRoot->getUniqueChild();
               delete pRoot;
               return temp;
           }
           else {
               BSTNode<E> *succesor= pRoot->getSuccessor();
               swap(pRoot,succesor);
               pRoot->setRight(removeAux(pRoot->getRight(),element));
               return pRoot;
           }
       }
   }

public:
   void clear(){
       clearAux(root);
       root=NULL;
   }
private:
   void clearAux(BSTNode<E> *pRoot){
       if(pRoot==NULL)return;
       clearAux(pRoot->getLeft());
       clearAux(pRoot->getRight());
       delete pRoot;
   }

public:
//   List<E> *getElements(){
//       List<E> *elements= new DlinkedList<E>();
//       getElementsAux(root,elements);
//       return elements;
//   }

//   void getElementsAux(BSTNode<E> pRoot,List<E> elements){
//       if(pRoot==NULL){return}
//       getElementsAux(pRoot.left,elements)
//       elements.append(pRoot.getElement());
//       getElementsAux(pRoot.right,elements);

//   }


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
#endif // ARBOLBINARIO_H
