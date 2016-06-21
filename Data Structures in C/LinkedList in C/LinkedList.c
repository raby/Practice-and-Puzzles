#include <stdio.h>
#include "LinkedList.h"

struct ll {
	int val;
	struct ll* next;
};

LinkedList newLinkedList(int v){
	LinkedList head = NULL;
	return head;
}

void printList(LinkedList head)
{
	printf("Printing LinkedList:\n[ ");
	struct ll* t = head;
	while(t!=NULL)
	{
    	printf("%d ",t->val);
		t = t->next;
	}
	printf("]\n");
}

LinkedList insertNode(LinkedList head, int v)
{	
	if(!head)
	{
		head = (LinkedList)malloc(sizeof(struct ll));
		head->val = v;
		head->next = NULL;
	}
	else
	{
		struct ll* t = (LinkedList)malloc(sizeof(struct ll));
		t->val = v;
		t->next = head;
		head = t;
	}
	return head;
}

LinkedList removeNode(LinkedList head, int v)
{
	if(!head)
		return head;

	struct ll* cur = head;
	struct ll* prev = cur;
	
	while(cur && v!=cur->val)
	{
		prev = cur;
		cur = cur->next;
	}
	if(!cur)
	{
		printf("Error: Invalid value, %d, to remove from Linked List\n", v);
		return head;
	}
	struct ll* td = cur;
	if(cur==prev)
	{
		head = cur->next;
		free(td);
	}
	else
	{
		prev->next = cur->next;
		free(td);
	}
	return head;
}

LinkedList insertNodeInOrder(LinkedList head, int v)
{
	if(!head)
	{
		head = (LinkedList)malloc(sizeof(struct ll));
		head->val = v;
		head->next = NULL;	
	}
	else
	{
		struct ll* cur = head;
		struct ll* prev = cur;
		while(cur && v < cur->val)
		{
			prev = cur;
			cur = cur->next;
		}
		struct ll* t = (LinkedList)malloc(sizeof(struct ll));
		t->val = v;
		t->next = NULL;
		if(cur==prev)
		{
			t->next = head;
			head = t;
			return head;
		}
		else if(cur)
			t->next = cur;	
		prev->next = t;
	}
	return head;
}

LinkedList sortList(LinkedList head)
{
	struct ll* i = head;
	struct ll* j = head;
	struct ll* min = i;

	while(i)
	{
		min = i;
		j = i;
		while(j=j->next)
		{
			if(j->val < min->val)
				min = j;
		}
		int temp = i->val;
		i->val = min->val;
		min->val = temp;
		i = i->next;
	}
	return head;
}

void deleteLinkedList(LinkedList head)
{
	struct ll* t = head;
	while(head)
	{
		head = head->next;
		free(t);
		t = head;
	}
}