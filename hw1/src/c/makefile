all: main main2

main:main.o stack.o
	gcc -o main main.o stack.o 

main2:main2.o stack.o
	gcc -o main2 main2.o stack.o 	

main.o:main.c
	gcc -c main.c

main2.o:main2.c
	gcc -c main2.c

stack.o:stack.c
	gcc -c stack.c

clean:
	rm -f *.o *.exe