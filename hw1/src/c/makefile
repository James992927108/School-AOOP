CC = gcc

all: main main2

main:main.o stack.o
	$(CC) main.o stack.o -o main

main2:main2.o stack.o
	gcc main2.o stack.o -o main2	

main.o:main.c
	$(CC) -c main.c

main2.o:main2.c
	gcc -c main2.c

stack.o:stack.c
	$(CC) -c stack.c

clean:
	rm -f *.o 