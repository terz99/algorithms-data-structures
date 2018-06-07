CC = g++
CFLAGS = -Wall

OBJ1 = fib_bottom_up.o 
OBJ2 = fib_naive.o 
OBJ3 = fib_matrix.o
OBJ4 = fib_closed_form.o
OBJ5 = fib_bottom_up_generator.o 
OBJ6 = fib_naive_generator.o 
OBJ7 = fib_matrix_generator.o
OBJ8 = fib_closed_form_generator.o

all: compile_bottom_up compile_naive compile_matrix compile_closed_form compile_bottom_up_generator compile_closed_form_generator compile_matrix_generator compile_naive_generator

compile_bottom_up: $(OBJ1)
		$(CC) $(CFLAGS) -o fib_bottom_up $(OBJ1)

compile_naive: $(OBJ2)
		$(CC) $(CFLAGS) -o fib_naive $(OBJ2)

compile_matrix: $(OBJ3)
		$(CC) $(CFLAGS) -o fib_matrix $(OBJ3)

compile_closed_form: $(OBJ4)
		$(CC) $(CFLAGS) -o fib_closed_form $(OBJ4)

compile_bottom_up_generator: $(OBJ5)
		$(CC) $(CFLAGS) -o fib_bottom_up_generator $(OBJ5)

compile_naive_generator: $(OBJ6)
		$(CC) $(CFLAGS) -o fib_naive_generator $(OBJ6)

compile_matrix_generator: $(OBJ7)
		$(CC) $(CFLAGS) -o fib_matrix_generator $(OBJ7)

compile_closed_form_generator: $(OBJ8)
		$(CC) $(CFLAGS) -o fib_closed_form_generator $(OBJ8)

fib_bottom_up.o: fib_bottom_up.cpp 

fib_naive.o: fib_naive.cpp 

fib_matrix.o: fib_matrix.cpp 

fib_closed_form.o: fib_closed_form.cpp

fib_bottom_up_generator.o: fib_bottom_up_generator.cpp 

fib_naive_generator.o: fib_naive_generator.cpp 

fib_matrix_generator.o: fib_matrix_generator.cpp 

fib_closed_form_generator.o: fib_closed_form_generator.cpp 

clean:
		rm -f fib_matrix fib_bottom_up fib_closed_form fib_naive fib_bottom_up_generator fib_matrix_generator fib_closed_form_generator fib_naive_generator *.o