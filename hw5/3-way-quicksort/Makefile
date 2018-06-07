CC = g++
CFALGS = -Wall

OBJ1 = quicksort.o 
OBJ2 = randomized_quicksort.o 

all: quicksort randomized_quicksort

quicksort: $(OBJ1)
		$(CC) $(CFLAGS) -o quicksort $(OBJ1)

randomized_quicksort: $(OBJ2)
		$(CC) $(CFLAGS) -o randomized_quicksort $(OBJ2)

quicksort.o: quicksort.cpp

randomized_quicksort.o: randomized_quicksort.cpp

clean:
		rm -f quicksort randomized_quicksort *.o