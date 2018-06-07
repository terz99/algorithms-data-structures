all: p1 p2 p3

p1: p1.cpp
		g++ -Wall p1.cpp -o p1

p2: p2.cpp algorithm.h
		g++ -Wall p2.cpp -o p2

p3: p3.cpp
		g++ -Wall p3.cpp -o p3

run-p1: p1
		./p1

run-p2: p2
		./p2

run-p3: p3
		./p3

clean:
		rm -f p1 p2 p3