CC = g++
CFLAGS = -Wall

OBJ1 = testStack.o

all: compile

compile: $(OBJ1)
		$(CC) $(CFLAGS) -o main $(OBJ1)

testStack.o: testStack.cpp

run:
		./main

clean: 
		rm -f main *.o