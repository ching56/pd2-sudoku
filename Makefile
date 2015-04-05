Solve: A.o main.cpp
	g++ -o solve main.cpp A.o
A.o: A.cpp
	g++ -c A.cpp -o A.o
