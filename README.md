# KBC-Game

<br>

### Team:
1. 2019B3PS0545P	Animesh Bhargava
2. 2019B4PS0704P	Utkarsh Yashvardhan
3. 2019A2PS0923P	Abhishek Anand

<br>

### Description of how to run the code and observe the output: 

1.	The c file is called 2019B3PS0545P_P3.c and is the only file required to run the program.

2.	To generate the executible, we need to compile the .c file through gcc.

3.	First of all, the terminal needs to be opened and the current directory needs to be set to the folder 2019B3PS0545P_P0 (project folder)

4.	Once, we are in the folder, we need to type the following command and hit enter:-
  	gcc 2019B3PS0545P_P3.c 

5.	The program will now compile and, besides the creation of executable file, a list of warnings will likely be generated.

6.	PLease ignore the warnings (if generated) as the program will run fine nevertheless.

7.	The default executable is named 'a.out' and to execute it, type the following command and hit enter:
  	./a.out
   
8.	The quiz game will now start. In the beginning the Welcome Page will be displayed.

9.	It is requested to view the program with the terminal in full screen mode, so that the program is easy to see and understand.
	Viewing in smaller window might cause some issues vis-a-vis interface and presentation.

10.	On pressing Enter, the rules page will come to the fore with the cursor at the bottom of the page.

11.	Once we have read the rules, we need to press the ENTER key to begin the game.

12.	The questions will be displayed one by one on the screen, starting with the first questions.

13.	With each question, the status consisting of the money won, at stake, lifelines, etc. will be displayed at the top.

14.	The question will be followed by 4 options and a set of instructions on which key to press for what purpose.

15.	It must be noted that after entering any character as input, we NEED to press the ENTER KEY.
	Only on pressing the Enter key, will the typed character be taken in as input.

16.	For availaing lifelines, the character 'L' needs to be entered, after which the available options will be displayed.
	Depending upon their availability, we need to enter '5' or 'F' for 50-50 and flip the question respectively.
	
17.	Once used, lifelines can't be used again. However both the lifelines can be used in one question.

18.	If the answer is correct, the program will prompt to continue by pressing Enter or quit by entering 'Q'.

19.	It must be noted that wherever Enter key has been asked for as input, typing two or more character strings can cause some errors.
	The second character can be perceived by the machine as the input for next question.
	
20.	After every correct answer a prompt will be displayed telling the amount of money won and asking to continue.
	We can quit the game anytime by entering Q when prompted.
	
21.	If the answer is wrong, the correct answer is displayed and the user is informed of the money won at the end. 

22.	The program exits when the user quits or gives a wrong answer or answers all the questions correctly.

23.	In the last case, a special message is displayed congratulating the user for winning the game.

 
<br>

### Known limitations of the code :

1.	The program contains all the features asked, but the game starts only when an enter key is pressed and not just by pressing any key.
	In fact every input requires an Enter key press to follow it.

2.	The program has limited number of questions which are already stored in the source code.

3.	The program doesn't store any user data, like name, money won etc. 

4.	The program interface is satic, hence it looks good only in full screen mode.

<br>

### Contributions of the team members:

Animesh Bhargava made the overall layout of the code as well as the functions related to display, checking the input and exit

Utkarsh Yashvardhan helped in display and designed the rules, lifelines and status functions

Abhishek Anand provided the questions and helped in the documentation of the code


<br>

							!!!!!THANK YOU!!!!!
							
					
