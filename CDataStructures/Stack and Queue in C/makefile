CC=gcc
CFLAGS=-I.
DEPS = Queue.h Stack.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

StackandQueueMake: Driver.o Queue.o Stack.o
	gcc -o StackandQueue Driver.o Queue.o Stack.o -I.