#include<iostream>

using namespace std;

class Sudoku{

	public:
		
		Sudoku(){for(i=0;i<sudokuSize;++i)map[i]=0;};
		Sudoku(const int init_map[]){for(i=0;i<sudokuSize;++i)map[i]=init_map[i];};
		
		void ReadIn(){for(i=0;o<sudokuSize;++i)cin >> map[i];};
		void Solve(){
			int judge = 0;
			int ps = nextBlank(-1);
			do{
				map[ps]++;
				if(map[ps] > 9){
					map[ps] = 0;
					previousBlank(ps);
				}else{
					if(check == true){
						recordBlank(ps);
						ps = nextBlanl(sp);
						if(ps == sudokuSize){
							ps = previousBlank(ps);
							judge++;
						}
					}
				}
			}while(ps >=  0 && ps < sudokuSize && judge < 2)
			cout << judge << endl;
			for(i = 0;i < sudokuSize;++i){
				cout << map[i];
				if(i % 12 == 0)cout << endl;
			}
		};
		void GiveQuestion();
		static const int sudokuSize = 144;

	private:
		void recordBlank(int ps){tmep_ps[temp_count++]=ps;};
		int nextBlank(int ps){
			do{ps++;}while( ps < sudokuSize && map[ps] > 0);
			return ps;
		};
		int previousBlank(int ps){
			if(temp_count < 0)return -1;
			ps = temp_ps[--tmep_count];
		};
		bool check(int arr[]){};
		int temp_ps[sudokuSize];
		int temp_count = 0; 
		int map[sudokuSize];
};
