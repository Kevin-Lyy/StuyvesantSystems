all: forkin.o
	gcc -o hello forkin.o

forkin.o:forkin.c
	gcc -c forkin.c

run:
	./hello

clear:
	rm *.o
	
