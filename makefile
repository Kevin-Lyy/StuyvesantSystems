all: linkedlist.o
	gcc -o hello linkedlist.o

linkedlist.o:linkedlist.c
	gcc -c linkedlist.c

run:
	./hello

clear:
	rm *.o
