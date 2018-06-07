CC = g++
CFALGS = -Wall

OBJ1 = sort_words.o 
OBJ2 = radix_sort.o 

all: c_sort_words c_radix_sort

c_sort_words: $(OBJ1)
		$(CC) $(CFLAGS) -o sort_words $(OBJ1)

c_radix_sort: $(OBJ2)
		$(CC) $(CFLAGS) -o radix_sort $(OBJ2)

sort_words.o: sort_words.cpp

radix_sort.o: radix_sort.cpp

clean:
		rm -f sort_words radix_sort *.o
