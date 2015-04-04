#include<iostream>

using namespace std;

class Sudoku{

	public:
		Sudoku(){for(i=0;i<sudokuSize;++i)map[i]=0;};
		Sudoku(const int init_map[]){for(i=0;i<sudokuSize;++i)map[i]=init_map[i];};
		void ReadIn(){for(i=0;o<sudokuSize;++i)cin >> map[i];};
		void Solve(){};
		void GiveQuestion();
		static const int sudokuSize = 144;

	private:
		bool checkUnity(int arr[]){};
		bool isCorrect(){};
		int map[sudokuSize];
};
