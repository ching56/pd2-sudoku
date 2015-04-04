#include<iostream>

using namespace std;

class Sudoku{

	public:
		
		Sudoku(){for(i=0;i<sudokuSize;++i)map[i]=0;};
		Sudoku(const int init_map[]){for(i=0;i<sudokuSize;++i)map[i]=init_map[i];};
		
		void ReadIn(){for(i=0;i<sudokuSize;++i)cin >> map[i];};
		void Solve(){
			int judge = 0;
			int ps = nextBlank(-1);
			do{
				map[ps]++;
				if(map[ps] > 9){
					map[ps] = 0;
					previousBlank(ps);
				}else{
					if(check(ps) == true){
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
		void findstart_row(int ps){
			return (ps - ( ps % 12 ) + 1);
		};
		void findstart_col(int ps){
			return ( ps % 12 )
		};
		void findstart_blo(int ps){
			return ( 1+(ps/36)*36+ps%12/3*3)
		};
		bool checkUnity(int arr[]){
			int arr[]_unity[9];
			for(i = 0;i < 9;i++)
				arr_unity[i]=0;
			for(i = 0;i < 12;i++){
				if(arr[i] != -1 )
					++arr_unity[arr[i]-1];
			}
			for(i = 0;i < 9;i++)
				if(arr_unity[i] != 1)
					return false;
			return true;	
		};
		bool check(int ps){
			int check_arr[12];
			int start;
			//check rows
			start = findstart_row(ps);
			for(i=0;i<12;i++)
				check_arr[i] = map[start + i];
			if(checkUnity(check_arr) == false)return false;
			//check colums
			start = findstart_col(ps);
			for(i=0;i<12;i++)
				check_arr[i] = map[start+i*12];
			if(checkUnity(check_arr) == false)return false;
			//check block
			start = findstart_blo(ps);
			for(i=0;i<12;i++)
				check_arr[i] = map[start+i/3*12+i%3];
			if(checkUnity(check_arr) == false)return false;
			return true;
		}
		int temp_ps[sudokuSize];
		int temp_count = 0; 
		int map[sudokuSize];
};
