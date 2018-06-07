CC = g++
CFLAGS = -Wall

OBJ1 = main.o LinkedList.o BinarySearchTree.o

all: compile

compile: $(OBJ1)
		$(CC) $(CFLAGS) -o main $(OBJ1)

main.o: BinarySearchTree.h LinkedList.h main.cpp

LinkedList.o: BinarySearchTree.h LinkedList.h LinkedList.cpp

BinarySearchTree.o: LinkedList.h BinarySearchTree.h BinarySearchTree.cpp

run:
		./main

clean: 
		rm -f main *.o