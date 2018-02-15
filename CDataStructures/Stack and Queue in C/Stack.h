#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack* Stack;
Stack newStack();

void printStack(Stack);
void pushStack(Stack*,int);
int topStack(Stack);
void popStack(Stack*);
void deleteStack(Stack);
bool emptyStack(Stack);
int sizeStack(Stack);

#endif