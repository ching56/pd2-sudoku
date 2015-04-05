#include<iostream>

using namespace std;

class Sudoku{

	public:
		
		Sudoku(){for(int i=0;i<sudokuSize;++i)map[i]=0;temp_count=0;};
		Sudoku(const int init_map[]){for(int i=0;i<sudokuSize;++i)map[i]=init_map[i];temp_count=0;};
		
		void ReadIn(){for(int i=0;i<sudokuSize;++i)cin >> map[i];};
		void Solve(){
			int judge = 0;
			int ps = nextBlank(-1);
			int i;
			do{
				map[ps]++;
				if(map[ps] > 9){
					map[ps] = 0;
					previousBlank(ps);
				}else{
					if(check(ps) == true){
						recordBlank(ps);
						ps = nextBlank(ps);
						if(ps == sudokuSize){
							ps = previousBlank(ps);
							judge++;
						}
					}
				}
			}while(ps >=  0 && ps < sudokuSize && judge < 2);
			cout << judge << endl;
			for(i = 0;i < sudokuSize;++i){
				cout << map[i];
				if(i % 12 == 0)cout << endl;
			}
		};
		void GiveQuestion();
		static const int sudokuSize = 144;

	private:

		int temp_ps[sudokuSize];
		int temp_count; 
		int map[sudokuSize];
		
		void recordBlank(int ps){temp_ps[temp_count++]=ps;};
		int nextBlank(int ps){
			do{ps++;}while( ps < sudokuSize && map[ps] > 0);
			return ps;
		};
		int previousBlank(int ps){
			if(temp_count < 0)return -1;
			ps = temp_ps[--temp_count];
		};
		int findstart_row(int ps){
			return (ps - ( ps % 12 ) + 1);
		};
		int findstart_col(int ps){
			return ( ps % 12 );
		};
		int findstart_blo(int ps){	
			return ( 1+(ps/36)*36+ps%12/3*3);
		};
		bool checkUnity(int arr[]){
			int arr_unity[9];
			int i;
			for(i = 0;i < 9;i++)
				arr_unity[i]=0;
			for(i = 0;i < 12;i++){
				if(arr[i] != -1 )
					++arr_unity[arr[i]-1];
			}
			for(i = 0;i < 9;i++)
				if(arr_unity[i] > 1)
					return false;
			return true;	
		};
		bool check(int ps){
			int check_arr[12];
			int start;
			int i;
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
};
