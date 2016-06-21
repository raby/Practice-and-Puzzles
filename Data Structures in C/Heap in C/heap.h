#ifndef HEAP_H
#define HEAP_H

struct heap
{
	int* data;
	int pos;
	int size;
};
	
struct heap h;

void printHeap();
void printSize();
void printpos();
void amortizeHeap();
void swap(int*, int*);
void perculateup(int);
void perculatedown(int);
void insert();
void remve();
int peek();
void construct();

#endif
