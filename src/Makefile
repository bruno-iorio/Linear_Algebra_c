all: main

main: main.o systems.o matrix.o vector.o
	gcc -o main main.o systems.o matrix.o vector.o

main.o: main.c
	gcc -c main.c

systems.o: systems.c 
	gcc -c systems.c

matrix.o: matrix.c
	gcc -c matrix.c

vector.o: vector.c
	gcc -c vector.c

clean: 
	rm main *.o
















