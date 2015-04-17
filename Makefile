all: Sudoku.o solve.cpp give_question.cpp SudokuVer1.o solveVer1.cpp SudokuVer2.o solveVer2.cpp SudokuVer3.1.o solveVer3.1.cpp
	g++ -o solve solve.cpp Sudoku.o
	g++ -o give_question give_question.cpp Sudoku.o
	g++ -o solveVer1 solveVer1.cpp SudokuVer1.o
	g++ -o solveVer2 solveVer2.cpp SudokuVer2.o
	g++ -o solveVer3.1 solveVer3.1.cpp SudokuVer3.1.o
Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o
SudokuVer1.o:SudokuVer1.cpp SudokuVer1.h
	g++ -o SudokuVer1.o -c SudokuVer1.cpp
SudokuVer2.o:SudokuVer2.cpp SudokuVer2.h
	g++ -o SudokuVer2.o -c SudokuVer2.cpp
SudokuVer3.1.o:SudokuVer3.1.cpp SudokuVer3.1.h
	g++ -o SudokuVer3.1.o -c SudokuVer3.1.cpp
clean:
	rm *.o
