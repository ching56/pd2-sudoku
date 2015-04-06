all: A.o solve.cpp give_question.cpp
	g++ -o solve solve.cpp A.o
	g++ -o give_question give_question.cpp A.o
A.o: A.cpp
	g++ -c A.cpp
