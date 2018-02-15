CC=gcc
CFLAGS=-I.
DEPS = BinaryTree.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BinaryTreeMake: Driver.o BinaryTree.o
	gcc -o BinaryTree Driver.o BinaryTree.o -I.