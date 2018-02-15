#include "BinaryTree.h"
#include <stdio.h>

struct binarytree
{
	int value;
	struct binarytree* left;
	struct binarytree* right;
};

BinaryTree newBT()
{
	BinaryTree root;
	root =  NULL;	
	return root;
};

void printBTLRR(BinaryTree bt)
{
	if(bt->left)
		printBTLRR(bt->left);
	printf("%d ",bt->value);
	if(bt->right)
		printBTLRR(bt->right);
}

void printBT(BinaryTree bt)
{
	printf("Printing Binary Tree: \n[ ");
	printBTLRR(bt);
	printf("]\n");
}

BinaryTree makeNode(int value)
{
	BinaryTree temp = (BinaryTree)malloc(sizeof(struct binarytree));
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void removeBT(BinaryTree* bt, int value)
{
	BinaryTree walk = *bt;
	BinaryTree parent = *bt;
	while(walk)
	{
		if(walk->left && value < walk->value)
		{
			parent = walk;
			walk = walk->left;
		}
		else if(walk->right && value > walk->value)
		{
			parent = walk;
			walk = walk->right;
		}
		else if(walk->value == value)
		{
			//case 1: node to remove has no leaves
			if(!walk->left && !walk->right)
			{
				if(parent->left == walk)
				 	parent->left = NULL;
				else
				  	parent->right = NULL;
			}
			//case 2: node to remove has one leaf
			else if(!walk->right)
			{
				if(parent->left == walk)
					parent->left = walk->left;
				else
					parent->right = walk->left;
			}
			else if(!walk->left)
			{
				if(parent->left == walk)
					parent->left = walk->right;
				else
					parent->right = walk->right;
			}
			//case 3: node to remove has two leaves
			else
			{
				BinaryTree t = walk->left;
				while(t->right)
				{
					parent = t;
					t=t->right;
				}
				walk->value = t->value;
				parent->right = NULL;
				free(t);
				return;
			}
			free(walk);
			return;
		}
		else
		{
			printf("Error: node to remove not found in tree.\n");
			return;
		}
	}	
}

void insertBT(BinaryTree* bt, int value)
{
	if(!(*bt))
		(*bt) = makeNode(value);
	else
	{
		BinaryTree walk = *bt;
		while(walk)
		{
			if(walk->left && value < walk->value)
				walk = walk->left;
			else if(!walk->left && value < walk->value)
			{
				walk->left = makeNode(value);
				break;
			}
			else if(walk->right && value > walk->value)
				walk = walk->right;
			else if(!walk->right && value > walk->value)
			{
				walk->right = makeNode(value);
				break;
			}
		}
	}
}

void deleteBT(BinaryTree bt)
{
}
