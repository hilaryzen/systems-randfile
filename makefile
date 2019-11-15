all: randfile.o
	gcc -o program randfile.o

randfile.o: randfile.c
	gcc -c randfile.c
