#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct binarytree* BinaryTree;

BinaryTree newBT();

void printBT(BinaryTree);
void printBTLRR(BinaryTree);
void insertBT(BinaryTree*, int);
void removeBT(BinaryTree*, int);
BinaryTree makeNode(int);

#endif