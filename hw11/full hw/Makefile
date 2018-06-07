all: p2 p3 p4

p2: problem2.cpp 
		g++ -Wall problem2.cpp -o p2

p3: problem3.cpp 
		g++ -Wall problem3.cpp -o p3

p4: problem4.cpp problem4.h 
		g++ -Wall problem4.cpp -o p4

run-p2: p2
		./p2

run-p3: p3
		./p3

run-p4: p4
		./p4

run-all: run-p2 run-p3 run-p4

clear:
		rm -f p2 p3 p4