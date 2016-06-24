#include "DLL.h"

int menu()
{
	int c;
	int val;
	printf("\nMENU: \n1. Insert to Front. \n2. Insert to Rear. \n3. Remove a Value. \n4. Print from Front. \n5. print from Rear. \n-1. Quit. \n");

	scanf("%d", &c);
	
	if(c==1)
	{
		printf("Input a value to Insert to Front. \n");
		scanf("%d",&val);
		insertFront(val);
	}
	else if(c==2)
	{
		printf("Input a value to Insert to Rear. \n");
		scanf("%d",&val);
		insertRear(val);	
	}
	else if(c==3)
	{
		printf("Input a value to remove. \n");
		scanf("%d",&val);
		removeValue(val);	
	}
	if(c==4)
		printFront();
	if(c==5)
		printRear();
	return c;
}
int main()
{

	printf("...:::Welcome to the DLL program:::...\n");
	int c = 0;
	while(c!=-1)
		c = menu();

	printf("Program complete. (press ENTER to exit)");
	getchar();	
	return 0;
}