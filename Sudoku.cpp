#include<iostream>
#include"Sudoku.h"
		
		//ctor
		Sudoku::Sudoku(){
			for(int i=0;i<sudokuSize;++i){
				map[i]=0;
				temp_ps[i]=0;
				ans[i]=0;
				}
			temp_count=0;
		}
		Sudoku::Sudoku(const int init_map[]){
			for(int i=0;i<sudokuSize;++i){
				map[i]=init_map[i];
				temp_ps[i]=0;
				ans[i]=0;
				}
			temp_count=0;
		}

		//the function to stdin the map
		void Sudoku::ReadIn(){
			for(int i=0;i<sudokuSize;++i){
				cin >> map[i];
				}
		}
		
		//the function to solve the sudoku stored in map[] by ReadIn()
		void Sudoku::Solve(){
			//judge stores the value mean to determine if it has only one answer, no answer or more then one
			int judge = 0;
			//ps is the position now solving
			//nextBlank(-1) move ps to the first blank
			int ps = nextBlank(-1);
			int i;
			//enter the solving loop
			do{	
				//find one number wich is bigger than the previous one in the blank and legal in the position, if no, return 0 and go to the following "if"
				map[ps]=FindOneBigger(ps);
				if(map[ps]==-2){judge=0;break;}
				//if there is no Bigger one, then go to previous one, if there isn't a previous one ,then return -1 ,it will cause the program exit the loop 
				if(map[ps] == 0){
					ps = previousBlank(ps);
				}else{
				//if there is a bigger one and legal ,record the ps and go next blank
					recordBlank(ps);
				//go to the next balnk, if no, go to Sudokusize( 144 ), and go to the following "if"
					ps = nextBlank(ps);
					if(ps == sudokuSize){
						//go to previous blank and repeat the method to check if there is another answer
						ps = previousBlank(ps);
						//make judge++
						judge++;
						//store the answer
						for(i=0;i<sudokuSize;i++)ans[i]=map[i];
					}
				}
			}while(ps >=  0 && ps < sudokuSize && judge < 2);
			//stdout the judge, if 0, no answer, if 1, one answer, if 2, more then one answer.
			cout << judge << endl;
			//when it's only an answer, output it!!
			if( judge == 1){
				for(i = 0;i < sudokuSize;++i){
					cout << ans[i]<<' ';
					if((i+1) % 12 == 0)cout << endl;
				}
			}
		}
			
		//the function to find one bigger and legal number in "ps"
		int Sudoku::FindOneBigger(int ps_t){

			int check_arr_row[12];
			int check_arr_col[12];
			int check_arr_blo[9];
			int arr_unity[9];
			int row_start;
			int col_start;
			int blo_start;
			int i,j=0;
			//initializer
			for(i=0;i<12;++i){
				check_arr_row[i]=0;
				check_arr_col[i]=0;
			}
			for(i=0;i<9;i++){
				check_arr_blo[i]=0;
				arr_unity[i]=0;
			}
			//input rows
			row_start = findstart_row(ps_t);
			for(i=0;i<12;i++)
				check_arr_row[i] = map[row_start + i];
			//input colums
			col_start = findstart_col(ps_t);
			for(i=0;i<12;i++)
				check_arr_col[i] = map[col_start+i*12];
			//input block
			blo_start = findstart_blo(ps_t);
			for(i=0;i<9;i++)
				check_arr_blo[i] = map[blo_start+i/3*12+i%3];
			//check which number is available
			for(i=0;i<12;i++){
				if(check_arr_row[i] != -1 && check_arr_row[i] != 0)
					++arr_unity[check_arr_row[i]-1];
				
				if(check_arr_col[i] != -1 && check_arr_col[i] != 0)
					++arr_unity[check_arr_col[i]-1];
			}
			for(i=0;i<9;i++){
				if(check_arr_blo[i] != -1 && check_arr_blo[i] != 0)
					++arr_unity[check_arr_blo[i]-1];
			}
			//return the lacked number bigger then old one
			for(i=0;i<9;i++){
				if(arr_unity[i]>3) return -2;
				if(arr_unity[i] == 0 && (i+1)>map[ps_t] ){
						return i+1;
					}

			}
			return 0;
		}
		//the function to stdout the randomly sudoku question
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
			int question[sudokuSize];
			int rand_num,i;
			
			//seed
			srand( (unsigned)time(NULL));
			//set a random number
			rand_num=rand()%9;
			//switch the number
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
			
		}

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
