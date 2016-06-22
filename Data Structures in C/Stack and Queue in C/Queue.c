#include "Queue.h"
#include "Node.h"
#include <stdio.h>

struct queue
{
	struct node* front;
	struct node* rear;
};

Queue newQueue()
{
	Queue q;
	q = (Queue)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void printQueue(Queue q)
{
	struct node* temp = q->rear;
	if(!temp)
	{
		printf("Printing Queue:\n[ ]\n");
		return;
	}
	printf("Printing Queue:\n[ ");
	printf("%d ",temp->val);
	while(temp=temp->next)
		printf("%d ",temp->val);
	printf("]\n");
}

void pushQueue(Queue* q, int val)
{
	struct node* temp = (Queue)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	temp->prev = NULL;

	//Case if Queue is empty.
	if(!(*q)->front)
		(*q)->front = (*q)->rear = temp;
	else if(!(*q)->rear)
	{
		(*q)->rear = temp;
		(*q)->rear->next = (*q)->front;
		(*q)->front->prev = (*q)->rear;
	}
	else
	{
		temp->next = (*q)->rear;
		(*q)->rear->prev = temp;
		(*q)->rear = temp;
	}
}

int frontQueue(Queue* q)
{
	if((*q)->front)
		return (*q)->front->val;
}


void popQueue(Queue* q)
{
	//Case if Queue is empty.
	if(!(*q)->front)
	{
		printf("Error: No items to dequeue. Queue is empty.\n");
		return;
	}
	else if((*q)->front == (*q)->rear)
	{
		struct node* t = (*q)->front;
		(*q)->front = (*q)->rear =  NULL;
		free(t);
	}
	else
	{
		struct node* t = (*q)->front;
		(*q)->front = (*q)->front->prev;
		(*q)->front->next = NULL;
		free(t);
	}
}

void deleteQueue(Queue q)
{
	if(q->rear)
		while(!emptyQueue(q))
			popQueue(q);
	free(q);
}

bool emptyQueue(Queue q)
{
	return (q->front) ? false : true;
}