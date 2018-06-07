CC = g++
CFLAGS = -Wall

OBJ1 = heapsort.o 
OBJ2 = bottom_up_heapsort.o 
OBJ3 = heapsort_generator.o
OBJ4 = bottom_up_heapsort_generator.o

all: compile_heapsort compile_heapsort_generator compile_bottom_up_heapsort compile_bottom_up_heapsort_generator

compile_heapsort: $(OBJ1)
		$(CC) $(CFLAGS) -o heapsort $(OBJ1)

compile_heapsort_generator: $(OBJ2)
		$(CC) $(CFLAGS) -o bottom_up_heapsort $(OBJ2)

compile_bottom_up_heapsort: $(OBJ3)
		$(CC) $(CFLAGS) -o heapsort_generator $(OBJ3)

compile_bottom_up_heapsort_generator: $(OBJ4)
		$(CC) $(CFLAGS) -o bottom_up_heapsort_generator $(OBJ4)

heapsort.o: heapsort.cpp 

bottom_up_heapsort.o: bottom_up_heapsort.cpp

heapsort_generator.o: heapsort_generator.cpp

bottom_up_heapsort_generator.o: bottom_up_heapsort_generator.cpp 

clean:
		rm -f heapsort heapsort_generator bottom_up_heapsort bottom_up_heapsort_generator *.o