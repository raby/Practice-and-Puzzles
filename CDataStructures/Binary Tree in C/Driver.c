#include "BinaryTree.h"

void procedures(BinaryTree bt)
{

	//add some nodes...print in order
	insertBT(&bt, 10);
	insertBT(&bt, 5);
	insertBT(&bt, 7);
	insertBT(&bt, 3);
	insertBT(&bt, 4);
	insertBT(&bt, 8);
	insertBT(&bt, 9);
	insertBT(&bt, 15);
	insertBT(&bt, 16);
	insertBT(&bt, 17);
	insertBT(&bt, 18);
	insertBT(&bt, 19);
	printBT(bt);

	//case 1: remove node no children
	removeBT(&bt, 19);
	printBT(bt);
	//case 2: remove node one child
	removeBT(&bt, 17);
	printBT(bt);
	//case 3: remove node two children
	removeBT(&bt, 5);
	printBT(bt);
	


}

int main()
{
	BinaryTree bt;
	bt = newBT();
	procedures(bt);
	system("pause");
}