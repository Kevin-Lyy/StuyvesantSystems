all: randfile.o
	gcc -o hello randfile.o

randfile.o:randfile.c
	gcc -c randfile.c

run:
	./hello

clear:
	rm *.o
