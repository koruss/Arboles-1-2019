#include <iostream>
#include "avltree.h"
#include "arbolbinario.h"

using namespace std;

int main()
{
 BSTree<int>* arbol= new BSTree<int>();
 AVLTree<int>* arbolito =new AVLTree<int>();
 arbol->insert(9);
 arbol->insert(21);
 arbol->insert(12);
// arbolito->insert(45);
// arbolito->insert(66);
// arbolito->insert(23);
// arbolito->insert(150);
 arbol->print();
}
