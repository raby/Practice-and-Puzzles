//Developed in Sublime Text / compiled with GCC 
//Created by David Pynes on 6/21/2016

#include "LinkedList.h"
LinkedList removalTesting(LinkedList ll)
{
	printf("\nRemoval Testing:\n");
	//case 1: remove from middle of list.
	ll = removeNode(ll, 5);
	printList(ll);
	
	//case 2: remove from start of list.
	ll = removeNode(ll,10);
	printList(ll);
	
	//case 3: remove from end of list.
	ll = removeNode(ll,1);
	printList(ll);

	//case 4: remove from out of bounds.
	ll = removeNode(ll, 112);
	printList(ll);

	return ll;
}

LinkedList insertionTesting(LinkedList ll)
{
	printf("\nInsertion Testing:\n");
	//case 1: insert in middle of list.
	ll = insertNodeInOrder(ll,5);
	printList(ll);

	//case 2: insert at start of list.
	ll = insertNodeInOrder(ll,15);
	printList(ll);
	
	//case 3: insert at end of list.
	ll = insertNodeInOrder(ll,0);
	printList(ll);
	
	return ll;
}

void procedures(LinkedList ll)
{
	//generate a list
	int i;
	for(i=1;i<=10;i++)
		ll = insertNode(ll, i);
	printList(ll);

	ll = removalTesting(ll);
	ll = insertionTesting(ll);

	printf("\nSort Testing:\n");
	//insert values out of order
	for(i=12;i<15;i++)
		ll = insertNode(ll,i);
	printList(ll);
	ll = sortList(ll);
	printList(ll);

}

int main()
{
	LinkedList ll;
	ll = newLinkedList();
	procedures(ll);

	printf("\n\nDestructing List:\n");
	deleteLinkedList(ll);
	printList(ll);
	
	system("pause");
	return 0;
}