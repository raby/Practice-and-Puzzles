#include "Stack.h"
#include "Node.h"
#include <stdio.h>

struct stack
{
	struct node* top;
	int size;
};

Stack newStack()
{
	Stack s;
	s = (Stack)malloc(sizeof(struct stack));
	s->top = NULL;
	s->size = 0;
	return s;
}

void printStack(Stack s)
{
	if(emptyStack(s))
	{
		printf("Printing Stack:\n[ ]\n");
		return;
	}
	else
	{
		printf("Printing Stack:\n[ ");
		struct node* t = s->top;
		while(t)
		{
			printf("%d ", t->val);
			t = t->prev;
		}
		printf("]\n");
	}
}

void pushStack(Stack* s, int val)
{
	struct node* t = (Stack)malloc(sizeof(struct node));
	t->prev = NULL;
	t->next = NULL;
	t->val = val;
	if(!(*s)->top)
		(*s)->top = t;
	else
	{
		(*s)->top->next = t;
		t->prev = (*s)->top;
		(*s)->top = t;
	}
	(*s)->size++;
}

int topStack(Stack s)
{
	return s->top->val;
}

void popStack(Stack* s)
{
	if(emptyStack(*s))
	{
		printf("Error: No items on stack to pop.\n");
		return;
	}
	else
	{
		struct node* t = (*s)->top;
		(*s)->top = (*s)->top->prev;
		free(t);
		(*s)->size--;
	}
}

void deleteStack(Stack s)
{
	if(s->top)
		while(!emptyStack(s))
			popStack(s);
	free(s);
}

bool emptyStack(Stack s)
{
	return sizeStack(s)==0 ? true : false;
}

int sizeStack(Stack s)
{
	return s->size;
}