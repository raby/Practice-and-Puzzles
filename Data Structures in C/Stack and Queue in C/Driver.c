//Created by David Pynes 6/21/2016
//Compiled with GCC

#include "Stack.h"
#include "Queue.h"

void stackProcedures(Stack s)
{
	int i;
	for(i=0;i<10;i++)
	{
		pushStack(&s,i);
		printStack(s);
	}
	printStack(s);
	printf("Size of stack: %d\n",sizeStack(s));

	while(!emptyStack(s))
	{
		popStack(&s);
		printStack(s);
		printf("Size of stack: %d\n",sizeStack(s));
	}

	//Error check: pop on a empty Stack.
	popStack(&s);
	printStack(s);		
	printf("Size of stack: %d\n\n",sizeStack(s));

}

void queueProcedures(Queue q)
{
	int i;
	for(i=0;i<10;i++)
	{
		pushQueue(&q,i);
		printQueue(q);
	}

	while(!emptyQueue(q))
	{
		popQueue(&q);
		printQueue(q);
	}

	//Error check: pop on a empty Queue.
	popQueue(&q);
	printQueue(q);
}

int main()
{
	Stack s;
	s = newStack();
	stackProcedures(s);

	Queue q;
	q = newQueue();
	queueProcedures(q);
	
	printf("\nDestructing Objects\n");
	deleteStack(s);
	deleteQueue(q);

	system("pause");
	return 0;
}