CC=gcc
CFLAGS=-I.
DEPS = LinkedList.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

LinkedListMake: Driver.o LinkedList.o 
	gcc -o LinkedList Driver.o LinkedList.o -I.