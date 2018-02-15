#define DLL_H
#ifndef DLL_H

typedef struct node* front;
typedef struct node* rear;

node makeNode(int);
void insertFront(int);
void insertRear(int);
void removeValue(int);
void printFront();
void printRear();

#endif