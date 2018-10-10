all: list.o
	gcc -o hello list.o

list.o:list.c
	gcc -c list.c

run:
	./hello

clear:
	rm *.o
