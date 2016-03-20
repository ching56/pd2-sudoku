# sudoku
Student ID: F74036467

The Report Of The Project 1: Sudoku

************************************************************************

Compile: make


Execute: ./give_question
	 ./solve


How to test the program:

	1.compile: make
	2.execute give_question: ./give_question>question.txt
	3.execute solve: ./solve<question.txt

About "solve", "solveVer1", "solveVer2", "solveVer3.1":

	"solve" is the file I would like to summited in this project."solveVer1", "solveVer2" and "solveVer3.1" are the executable file made by "make".They're the version I made which use different method and ran slower then the "solve", but still work,they are the older version of solve. More details are in the following.

How did I do my project:

	1.solve:

		version 1) try one by one
		
		In version 1, I fill the number into the blank one by one until it's legal, and move to the next and blank do the same thing. If there isn't any legal answer in the blank, then fill zero and return to the previous blank,and try the next answer. If it does not find any other answer and back to the first blank, it means it's a no answer Sudoku.Or when it finds the answer of the last blank, then it return to the previous blank try next possbile, and repeat it.Try if there is another answer.

		version 2) store the all possible answer of the blanks first and try, run appromxiately (0.8*version1's running time)
		
		In version 2, to improve the efficency of version 1, I check the possbile answers of all blanks first and store it. Then use the same method as version one, but only try the possible answer instead of every one.

	***THE SUMMITED VERSION***
		version 3) try the least legal one, run appromixately (0.4*version1's running time)

		In version 3, to improve the efficency of version 1 and not make the logic too complicated, try to chcek the possible answer when filling the blank instead of store it first. It can avoid the previous error, and run 1/3 time as the version 1. And it's the submitted version.
	**************************
		
		version 3.1) based on version 3, but the position of filling the blank is randomly instead of in order.

		In version 3.1, to avoid program running the particular question too long, I did some change in the order of filling position. For example if lots of blanks in a column, because of the algorithm is solving by line, the blanks in column may cause much time. So I change the filling order in random. But I even did more time then version 1. I guess the randomly order make the solving more complicated, so it's failed.
		
	2.give question:

		step 1) build the model

		I build the model Sudoku by copy the one on the slide of the project. To make more 0 on the model, I replace the number to 0 one by one, and test in "solve" if it has only a answer, if not then recover it, if yes then do next one. Then I get the question model of Sudoku with lots of zero.

		step 2) replace the number

		replace the number of model except 0, -1 to another number. One number to one number, so the relations of the number is the same, is still one answer, furthermore there is 9! possible question.
		
		3) mirro and turn
		
		Randomly make the model after step 2 upside down, or mirro. Then the result is the output of "give_question".
		

***********************************************************************
