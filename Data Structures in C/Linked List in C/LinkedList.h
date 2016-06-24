typedef struct ll * LinkedList;
LinkedList newLinkedList();

void printList(LinkedList);
LinkedList insertNode(LinkedList,int);
LinkedList insertNodeInOrder(LinkedList,int);
LinkedList removeNode(LinkedList,int);
LinkedList sortList(LinkedList);
void deleteLinkedList(LinkedList);
