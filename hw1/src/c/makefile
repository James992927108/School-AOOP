CC = gcc -Wall

all: main main2

main:stack.o main.o
	$(CC) stack.o main.o -o main

main2:main2.o stack.o
	$(CC) main2.o stack.o -o main2	

main.o:main.c
	$(CC) -c main.c

main2.o:main2.c
	$(CC) -c main2.c

stack.o:stack.c
	$(CC) -c stack.c

clean:
	rm -f *.o main