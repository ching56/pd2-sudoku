#include<iostream>
#include"SudokuVer1.h"

		
		Sudoku::Sudoku(){for(int i=0;i<sudokuSize;++i){map[i]=0;temp_ps[i]=0;ans[i]=0;}temp_count=0;};
		Sudoku::Sudoku(const int init_map[]){for(int i=0;i<sudokuSize;++i){map[i]=init_map[i];temp_ps[i]=0;ans[i]=0;}temp_count=0;};
		
		void Sudoku::ReadIn(){for(int i=0;i<sudokuSize;++i){cin >> map[i];ans[i]=map[i];};};
		void Sudoku::Solve(){
			int judge = 0;
			int ps = nextBlank(-1);
			int i;
			int counter=0;
			do{	
				//test
				//counter++;
				map[ps]++;
				if(map[ps] > 9){
					map[ps] = 0;
					ps = previousBlank(ps);
				}else{
					if(check(ps) == true){
						recordBlank(ps);
						ps = nextBlank(ps);
						if(ps == sudokuSize){
							ps = previousBlank(ps);
							judge++;
							for(i=0;i<sudokuSize;i++)ans[i]=map[i];
						}
					}
				}
			}while(ps >=  0 && ps < sudokuSize && judge < 2);
			cout << judge << endl;
			if( judge == 1){
				for(i = 0;i < sudokuSize;++i){
					cout << ans[i]<<' ';
					if((i+1) % 12 == 0)cout << endl;
				}
			}
			//test
			//cout<<"do "<<counter<<" times"<<endl;
		};
		void Sudoku::GiveQuestion(){
			
			//the model question
			int model[sudokuSize] = {0, 2, 0, 0, 0, 0, 0, 0, 1, -1, -1, -1,
						0, 0, 3, 9, 5, 0, 0, 0, 0, -1, -1, -1,
						0, 0, 0, 0, 0, 4, 0, 0, 0, -1, -1, -1,
						-1, -1, -1, 0, 0, 0, 0, 8, 7, 0, 0, 6,
						-1, -1, -1, 0, 8, 0, 0, 0, 0, 0, 2, 0,
						-1, -1, -1, 4, 0, 6, 0, 0, 0, 0, 0, 0,
						1, 0, 0, 0, 0, 0, -1, -1, -1, 0, 9, 0,
						0, 0, 4, 0, 6, 0, -1, -1, -1, 0, 0, 7,
						0, 0, 5, 0, 1, 7, -1, -1, -1, 0, 8, 0,
						0, 1, 0, -1, -1, -1, 7, 0, 0, 5, 0, 9,
						7, 0, 8, -1, -1, -1, 0, 6, 0, 3, 0, 2,
						0, 6, 0, -1, -1, -1, 3, 1, 0, 0, 0, 0};
			//randomly
			int question[sudokuSize];
			int rand_num,i;

			srand( (unsigned)time(NULL));
			rand_num=rand()%9;
			for(int i=0;i<sudokuSize;i++){
				if(model[i] != 0 && model[i] != -1){
					model[i]=(model[i]+rand_num)%10;
						if(model[i]==0)
							model[i]=rand_num;
				}
			}
			
			for(i=0;i<sudokuSize;i++)question[i]=model[i];
			rand_num=rand()%6+1;

			//turn 
			if(rand_num==1){
				for(i=0;i<sudokuSize;i++)
					question[i]=model[sudokuSize-i-1];
			}
			//mirro
			if(rand_num==2){
				for(i=0;i<sudokuSize;i++)
					question[i]=model[(i/12)+(i%12)*12];
			}
			//up 2 to down 2
			if(rand_num==3){
				for(i=0;i<sudokuSize/2;i++)
					question[i]=model[sudokuSize/2+i];
				for(i=sudokuSize/2;i<sudokuSize;i++)
					question[i]=model[i-sudokuSize/2];

			}
			//output
			for(i=0;i<sudokuSize;i++){
				cout<<question[i]<<" ";
				if((i+1)%12==0)
					cout<<endl;}
			
			};

		void Sudoku::recordBlank(int ps){temp_ps[temp_count++]=ps;};
		int Sudoku::nextBlank(int ps){
			do{ps++;}while( ps < sudokuSize && map[ps] > 0 || map[ps] == -1);
			return ps;
		};
		int Sudoku::previousBlank(int ps){
			if(temp_count == 0)return -1;
			ps = temp_ps[--temp_count];
			return ps;
		};
		int Sudoku::findstart_row(int ps){
			return (ps - ( ps % 12 ));
		};
		int Sudoku::findstart_col(int ps){
			return ( ps % 12 );
		};
		int Sudoku::findstart_blo(int ps){	
			return ((ps/36)*36+ps%12/3*3);
		};
		bool Sudoku::checkUnity(int arr[]){
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
		
		bool Sudoku::check(int ps){
			int check_arr[12];
			int row_start;
			int col_start;
			int blo_start;
			int i;
			for(i=0;i<12;++i)check_arr[i]=0;
			//check rows
			row_start = findstart_row(ps);
			for(i=0;i<12;i++)
				check_arr[i] = map[row_start + i];
			if(checkUnity(check_arr) == false){return false;};
			//check colums
			col_start = findstart_col(ps);
			for(i=0;i<12;i++)
				check_arr[i] = map[col_start+i*12];
			if(checkUnity(check_arr) == false){return false;};
			//check block
			blo_start = findstart_blo(ps);
			for(i=0;i<12;i++)check_arr[i]=0;
			for(i=0;i<9;i++)
				check_arr[i] = map[blo_start+i/3*12+i%3];
			if(checkUnity(check_arr) == false){return false;};
			return true;
		}
