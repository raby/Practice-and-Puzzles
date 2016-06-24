#include "DLL.h"
#include <stdio.h>

struct DLL* front;
struct DLL* rear;
typedef struct DLL* node;

struct DLL
{
	int val;
	struct DLL* next;
	struct DLL* prev;
};


node makeNode(int v)
{
	node t = (node)malloc(sizeof(struct DLL));
	t->val = v;
	t->next = NULL;
	t->prev = NULL;
	return t;
}

void insertFront(int v)
{
	node temp = makeNode(v);
	if(!front)
			front = rear = temp;
	else
	{
		temp->prev = front;
		front->next = temp;
		front = temp;
	}
}

void insertRear(int v)
{
	node temp = makeNode(v);
	if(!rear)
		front = rear = temp;
	else
	{
		temp->next = rear;
		rear->prev = temp;
		rear = temp;
	}
}

void removeValue(int v)
{
	node rTemp = rear;
	node fTemp = front;
	while(rTemp && fTemp)
	{
		//case 1: the node is found in the rear half of the list.
		if(rTemp->val == v)
		{
			if(rTemp->prev)
			{
				rTemp->prev->next = rTemp->next;
				rTemp->next->prev = rTemp->prev;
			}
			else
			{
				rear = rear->next;
				rTemp->next->prev = NULL;
			}
			if(fTemp->prev == rTemp)
			{
				if(rTemp->prev)
					fTemp->prev = rTemp->prev;
				else
					fTemp->prev = NULL;
			}
			free(rTemp);
			return;
		}
		//case 2: the node is found in the front half of the list.
		else if(fTemp->val == v)
		{
			if(fTemp->next)
			{
				fTemp->next->prev = fTemp->prev;
				fTemp->prev->next = fTemp->next;
			}
			else
			{
				front = front->prev;
				fTemp->prev->next = NULL;
			}
			if(rTemp->next == fTemp)
			{
				if(rTemp->next)
					rTemp->next = fTemp->next;
				else
					rTemp->next = NULL;
			}
			free(fTemp);
			return;
		}
		//advance pointers
		rTemp = rTemp->next;
		fTemp = fTemp->prev;
	}
	printf("Error: Value not found in list. \n");
}

void printFront()
{
	node temp = front;
	printf("Printing from the front of the list: \n[ ");
	while(temp)
	{
		printf("%d ",temp->val);
		temp = temp->prev;
	}
	printf("]\n");
}

void printRear()
{
	node temp = rear;
	printf("Printing from the rear of the list: \n[ ");
	while(temp)
	{
		printf("%d ",temp->val);
		temp = temp->next;
	}
	printf("]\n");
}