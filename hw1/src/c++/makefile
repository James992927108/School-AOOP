CC = g++

all: main main2

main:main.o stack.o
	$(CC) main.o stack.o -o main

main2:main2.o stack.o
	$(CC) main2.o stack.o -o main2	

main.o:main.cpp
	$(CC) -c main.cpp

main2.o:main2.cpp
	$(CC) -c main2.cpp

stack.o:stack.cpp
	$(CC) -c stack.cpp

clean:
	rm -f *.o 