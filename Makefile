all: Sudoku.o solve.cpp give_question.cpp
	g++ -o solve solve.cpp Sudoku.o
	g++ -o give_question give_question.cpp Sudoku.o
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
