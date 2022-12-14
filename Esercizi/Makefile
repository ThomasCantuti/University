figure: main.o Figure.o
	gcc -o figure main.o Figure.o -lm

main.o: main.c Figure.h
	gcc -c main.c

Figure.o: Figure.c Figure.h
	gcc -c Figure.c