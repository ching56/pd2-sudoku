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
		void GetPossibility(int ps_t);
		void SetPossibility(int ps_t);
		int possibility[sudokuSize][10];
		int temp_ps[sudokuSize];
		int temp_count;
		int ans[sudokuSize];
		int map[sudokuSize];
		void InputPossibility();	
		void recordBlank(int ps);
		int nextBlank(int ps);
		int previousBlank(int ps);
		int findstart_row(int ps);
		int findstart_col(int ps);
		int findstart_blo(int ps);
		bool checkUnity(int arr[]);		
		bool check(int ps);
};
