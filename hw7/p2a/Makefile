CC = g++
CFLAGS = -Wall

OBJ1 = main.o LinkedList.o

all: compile

compile: $(OBJ1)
		$(CC) $(CFLAGS) -o main $(OBJ1)

main.o: LinkedList.h main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp

run:
		./main

clean: 
		rm -f main *.o