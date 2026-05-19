all: exec

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -o fonction.o

main.o: main.c fonction.h
	gcc -c main.c -o main.o

exec: main.o fonction.o
	gcc main.o fonction.o -o exec

clean:
	rm exec
	rm *.o
