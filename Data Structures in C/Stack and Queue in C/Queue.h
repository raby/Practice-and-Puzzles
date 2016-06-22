#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue* Queue;
Queue newQueue();

void printQueue(Queue);
void pushQueue(Queue*,int);
int frontQueue(Queue*);
void popQueue(Queue*);
void deleteQueue(Queue);
bool emptyQueue(Queue);

#endif