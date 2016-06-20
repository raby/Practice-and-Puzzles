#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "heap.h"

void printHeap()
{
	printf("The heap contains: \n[ ");
	int i;
	for(i=0;i<h.pos;i++)
		printf("%d ",h.data[i]);
	printf("]\n");
}

void printSize()
{
	printf("Size of Heap: %d\n",h.size);
}

void printPos()
{
	printf("Position on heap: %d\n",h.pos);
}

	
void amortizeHeap()
{
	h.data = (int*) realloc(h.data, h.pos*2);
	h.size = h.pos*2;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void perculateup(int n)
{
	int l = (n/2);
	int r = (n/2)-1;
	if(r<0)
	{
		if(h.data[n] < h.data[l])
			swap(&h.data[n], &h.data[l]);
	}
	else if(h.data[n] < h.data[l] && h.data[r])
	{
		swap(&h.data[n],&h.data[l]);
		perculateup(l);
	}
	else if(h.data[n] < h.data[r])
	{
		swap(&h.data[n],&h.data[r]);
		perculateup(r);
	}
}

void perculatedown(int n)
{
	int l = 2*n+1;
	int r = 2*n+2;
	int min = -1;
	if(r>=h.pos)
	{
		if(l==1 && h.data[n] > h.data[l])
			swap(&h.data[n],&h.data[l]);
		return;
	}
	if(h.data[n] > h.data[l])
	{
		if(h.data[r] < h.data[l])
		{
			swap(&h.data[n],&h.data[r]);
			perculatedown(r);
		}
		else
		{
			swap(&h.data[n],&h.data[l]);
			perculatedown(l);	
		}
	}
	else if(h.data[n] > h.data[r])
	{
		if(h.data[l] < h.data[r])
		{
			swap(&h.data[n],&h.data[l]);
			perculatedown(l);
		}
		else
		{
			swap(&h.data[n],&h.data[r]);
			perculatedown(r);
		}
	}	
}

void construct()
{
	h.data = malloc(1 *sizeof *h.data);
	h.pos = 0;
	h.size = 1;
}
void insert()
{
	int v = 0;
	printf("Assign a value to insert into heap:\n");
	scanf("%d", &v);
	if(h.pos >= h.size )
		amortizeHeap();
	h.data[h.pos] = v;
	perculateup(h.pos++);
}

void remve()
{
	swap(&h.data[0],&h.data[--h.pos]);
	perculatedown(0);
}

int peek()
{
	printf("The top of the heap is: %d\n", h.data[0]);
}
