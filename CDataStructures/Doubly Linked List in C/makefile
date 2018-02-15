CC=gcc
CFLAGS=-I.
DEPS = DLL.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

DLL: Driver.o DLL.o
	gcc -o DoubleLinkedList Driver.o DLL.o -I.