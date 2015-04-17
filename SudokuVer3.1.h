#include<iostream>
#include<cstdlib>// rand
using namespace std;

class Sudoku{

	public:
		
		Sudoku();
		Sudoku(const int init_map[]);
		
		void ReadIn();
		void Solve();
		void GiveQuestion();

		static const int sudokuSize = 144;

	private:
		int Blank[sudokuSize];
		int RandomBlank();
		int sequence[sudokuSize];
		int FindOneBigger(int ps_t);
		int temp_ps[sudokuSize];
		int temp_count;
		int ans[sudokuSize];
		int map[sudokuSize];		
		void recordBlank(int ps);
		int nextBlank(int ps);
		int previousBlank(int ps);
		int findstart_row(int ps);
		int findstart_col(int ps);
		int findstart_blo(int ps);
		bool checkUnity(int arr[]);		
		bool check(int ps);
};
