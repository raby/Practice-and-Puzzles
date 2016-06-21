#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "heap.h"

//Created by David Pynes
//Coded in Sublime / Compiled with GCC / for build use makefile


void menu()
{
	printf("\n\n1. Insert into heap \n2. Remove from heap \n3. Peek \n4. Print \n5. Print Size \n6. Print Position \n7. Quit \n");
}

int main(int argc, char *argv[]) 
{
	int c=1;
	construct();
	while(c!=0)
	{
		menu();
		scanf("%d",&c);
		if(c==1)
			insert();
		else if(c==2)
			remve();
		else if(c==3)
			peek();
		else if(c==4)
			printHeap();
		else if(c==5)
			printSize();
		else if(c==6)
			printPos();
		else if(c==7)
			c=0;
	}
	return 0;
}