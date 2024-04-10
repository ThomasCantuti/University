programma: main.o funzioni.o
	gcc -g -o programma main.o funzioni.o

main.o: main.c funzioni.h
	gcc -g -c main.c

funzioni.o: funzioni.c funzioni.h
	gcc -g -c funzioni.c