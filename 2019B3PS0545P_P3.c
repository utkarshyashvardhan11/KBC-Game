/**	CSF111 Assignment
	Assignment question attempted : QUESTION 1
	Title : KBC game using C	  
	Practical Section number : P3
	Instructor name :	Ms Sakshi
	Students Involved :	Animesh Bhargava 	2019B3PS0545P
				Utkarsh Yashvardhan	2019B4PS0704P
				Abhishek Anand		2019A2PS0923P
				
*/

/* Header files inclusion */
#include <stdio.h> 	// To include functions such as printf(), scanf() etc.
#include <stdlib.h>	// To include functions such as system(), exit() etc.
#include <string.h>	// To include functions like strcmp() etc.
#include <ctype.h>	// To include functions like toupper() etc.
#include <time.h> 	// To include functions like time()



/* Declaration and initialization of an array 'set' of structure named 'questions' consisting of string q[] to store question, strings A[], B[], C[], D[] to store options and correct_answer[] to store the correct answer corresponding to each question */
struct questions{
    char q[100] ;
    char A[25] ;
    char B[25];
    char C[25];
    char D[25];
    char correct_answer[25];


} set[]={
	{"What part of a coffee plant is used to prepare the beverage?", "Beans", "Bark", "Root", "Leaves", "Beans"},
	{"Which of these is not a number?", "Million", "Billion", "Trillion", "Pillion", "Pillion"},
	{"In which of the following games is the term 'deuce' used?", "Tennis", "Golf", "Chess", "Cricket", "Tennis"},
	{"In Hindu mythology, whose elder brother was Balrama?", "Rama", "Krishna", "Parshurama", "Arjuna", "Krishna"},
	{"What was the name given to the first cloned sheep?", "Sally", "Dolly", "Molly", "Polly", "Dolly"},
	{"The name of which state literally means 'The Land of Gems'?", "Meghalaya", "Nagaland", "Manipur", "Mizoram", "Manipur"},
	{"What is the minimum age to be eligible for election as President of India?", "25 years", "30 years", "40 years", "35 years", "35 years"},
	{"Which capital city do Heathrow and Gatwick airports serve?", "London", "Canberra", "Washington DC", "Dublin", "London"},
	{"Where are the headquarters of OPEC?", "Tehran", "Riyadh", "Vienna", "Geneva", "Vienna"},
	{"In Olympic archery, what is the colour of the central ring of the target?", "White", "Red", "Yellow", "Black", "Yellow"},
	{"Who was the first ruling British monarch to visit India?", "George V", "Elizabeth II", "Edward VIII", "Victoria", "George V"},
	{"Which of these actors has not played nine different roles in one film?", "Sivaji Ganesan", "Sanjeev Kumar", "Chiranjeevi", "A Nageshwar Rao", "Chiranjeevi"},
	{"What is the Japanese business philosophy of continuous improvement called?", "Karaoke", "Kaizen", "Kamikaze", "Kimono", "Kaizen"},
	{"Who was the first person to walk in space?","Alexei Leonov", "John  Glenn", "Leonid Kizim", "Yuri Romanenko", "Alexei Leonov"},
	{"Where in India is the world's only floating wildlife sanctuary located?", "Manipur", "Meghalaya", "Assam", "Tripura", "Manipur"},
	{"How do we better know the Urdu poet Akhtar Hussain Rizvi?", "Sahir Ludhianvi", "Kaifi Azmi", "Javed Akhtar", "Faiz Ahmed Faiz", "Kaifi Azmi"},
	{"How many characters made up of combinations of dots are used in Braille?", "69", "82", "87", "63", "63"},
	{"Which of these England Test captains was not born in India?", "Nasser Hussain", "Ted Dexter", "Douglas Jardine", "Colin Cowdrey", "Ted Dexter"},
	{"From which language has the word 'Punjab' been derived?", "Greek", "Arabic", "Persian", "Sanskrit", "Persian"},
	{"Which of these sports has never featured at the Olympics?", "Cricket", "Tug of War", "Polo", "Bowls", "Bowls"},
	{"Who invented the oral polio vaccine (OPV)?", "Albert Sabin", "Ronald Ross", "Jonas Salk", "Francis Crick", "Albert Sabin"},
	{"Which of these persons was never appointed Acting President of India?", "V V Giri", "Fakhruddin Ali Ahmed", "M Hidayatullah", "B D Jatti", "Fakhruddin Ali Ahmed"},
	{"Where was the world's first fingerprinting bureau established?", "New York", "Paris", "Kolkata", "London", "Kolkata"},
	{"Who was the first woman to be appointed Chief Justice of a High Court in India?", "Noor Fatima Bibi", "Anna Chandy", "Lala Patel", "Leila Seth", "Leila Seth"},
	{"Arati Pradhan became the first woman in the world to swim across which water body in 1988?", "English Channel", "Bosphorus", "Strait of Gibraltar", "Palk Strait", "Strait of Gibraltar"},
	{"Who was the first Secretary of State and third President of the United States of America?", "James Madison", "John Quincy Adams", "Thomas Jefferson", "James Monroe", "Thomas Jefferson"},
	{"Which is the southernmost point of the continent of Africa?", "Cape Aghulas", "Cape Horn", "Cape of Good Hope", "Cape Hatteras", "Cape Aghulas"},
	{"Which actor captained England in his only appearance in Test cricket?", "William Holden", "C Aubrey Smith", "Alan Ladd", "W C Fields", "C Aubrey Smith"},
	{"Who first climbed the highest peaks on each of all the seven continents?", "Daniel Johnson", "Phil Hartman", "Dick Bass", "Reinhold Messner", "Dick Bass"},
	{"Who was the first woman to produce a Hindi film, in which she also acted?", "Fatima Begum", "Kamla Bai", "Nasreen", "Zubeida", "Fatima Begum"}
};  
// There are 30 structure element sets where set[i] refers to the (i-1)th structure element



/*Declaration of Global variables used in the program:- */

int fiftyFifty = 1;
int flipQues = 1;
/* fiftyFifty and flipQues are int variables denoting the availability of lifelines 50-50 and flip the question respectively. They are initialized to 1, denoting that they are both available initially */


char userAnswer; // to store the user input (option answered or R or L or Q as per need)

char next; // to store user input to determine if they want to continue or quit

char op1, op2; // to store the options of 50-50 lifeline to be printed

char prizeMoney[][10] = {"0" ,"5,000", "10,000", "20,000", "40,000", "80,000", "1,60,000", "3,20,000", "6,40,000", "12,50,000", "25,00,000", "50,00,000", "1 Crore", "3 Crore", "5 Crore", "7 Crore"};
/* prizeMoney is an array of string (2D char array) to store prize money corresponding to question number(index of array) */

int correctAnswers = 0;   // to store the number of questions correctly answered by the user

int currentLevel = 0;   // to denote the latest 'milestone' question (3 or 8 or 12) answered correctly


/* Function Prototype of various functions used in the program apart from main */

// Functions to display rules, questions, status etc.
void welcome(void);
void rules(void);
void status(void);
void display_Lifelines(void);
void display(struct questions*, int*);
void display_Options(struct questions*);

// Functions to take user input
void continue_Ahead(void);
void take_Input(void);
void validate_Response(int*);
int appropriate_Input(char);

// Functions to respond to user input
void check_Response(struct questions*, int*);
int check_Correct_Answer(char, int);
char correct_Option(struct questions*);
void activate_Lifelines(int*);
void level_Update(void);

// Lifeline Functions
void call_Lifeline(int*);
void flip_Question(int*);
void fifty_Fifty(struct questions*, int*);
char random_Generate(void);

// Exit Functions
void leave_Game(void);
void winner_Message(void);



/* The main function, which is executed when the program is run */

int main( ) {

	welcome(); //Displaying the welcome page
	
	rules(); // First of all the rules are displayed in the program
	
	int i = 0; // Counter variable denoting the index of question set from the struct to be displayed
	
	/* Loop until the last index of struct array (with skips of 2) */
	while(i < 30) {
		
		display (set + i, &i); // Calling the display function with pointers to question and index as arguments
	
	}
	
	return 0;
}



/* A welcome page for the contestant */
void welcome() {
	
	system("clear"); /* Clears the output screen */

	printf("\t\t\t\t--------------------------------------------------------\n\n\n");
	printf("\t\t\t\t\t\tKBC	QUIZ	GAME\n\n");
	printf("\t\t\t\t________________________________________________________\n\n\n");
	printf("\t\t\t\t\t\t	WELCOME   \n\n");
	printf("\t\t\t\t\t\t          to     \n\n");
	printf("\t\t\t\t\t\t       THE QUIZ   \n\n");
	printf("\t\t\t\t________________________________________________________\n\n\n");
	printf("\t\t\t\t\t\tLet's become a CROREPATI!!!!\n\n\n");
	printf("\t\t\t\tPress enter to begin....");
	continue_Ahead();
	
}


/* Function to display the rules */

void rules(){
	
	system("clear"); /* Clears the screen */

	printf("\n\t\t\t--------------------------------------RULES---------------------------------------------\n\n");
	
	/*Bullet points of the rules */
	printf("\t>> The game consists of a total number of 15 questions, having 4 options each.\n");
	printf("\t   The contestant needs to answer all of these question in order to win the top cash prize.\n\n");
	printf("\t>> The prize money associated with each question is given as follows : -\n\n");

	// List of prize money corresponding to each question
	printf("               Question no.\t\t\tPrize Money\n\n");
	for(int i = 1; i <= 15; i++){
		if(i == 3 || i == 8 || i == 12){
			printf("                  *%d\t\t\t\t₹%s\n", i, prizeMoney[i]);

        	}
        	else
        		printf("                   %d\t\t\t\t₹%s\n", i, prizeMoney[i]);
    	}

    	printf("\n\n\tThe questions marked with '*' indicate the milestone questions.\n\n");
    	
    	printf("\t>> At any time, the contestant is free to walk away from the game with their winnings. \n");
    	printf("\t   However, on giving a wrong answer, they will fall back to the last milestone they have crossed.\n\n");
    	
    	printf("\t>> To help the players, a set of lifelines are available to be used only once.\n\n");
    	printf("\t   These are : -\n\n");
    	printf("\t   (i) 50 - 50 ('5') -> The computer will remove two wrong answers from the game.\n\n");
    	printf("\t   (ii) Flip the question ('F') -> The current question will be replaced with a new question. \n\n");
    	printf("\t   If you wish to use one of your lifelines, enter 'L' to activate the available lifelines.\n\n");
    	
    	printf("\t>> To quit the game at any time, press 'Q'.\n\n");
    	printf("\t>> To see the rules anytime, press 'R'.\n\n");
    	printf("\t>> To answer the question, you need to type in 'A', 'B', 'C', or 'D', accordingly.\n\n");
    	
    	
    	printf("\t\t\t\t-------------------------------------------------------------\n");
    	
    	// Message prompting user to press enter to continue
    	printf("Press Enter key to continue.");
    	if (userAnswer != 'R')
    		continue_Ahead(); // Calling continue_Ahead() function to accept the user input
    		
}



/* Functions to display the current status (Money won) as well as the outcome of answering the next question right or wrong, besides displaying the lifelines available at that point */
void status() {

	printf("\n\t\t--------------------------------------------------QUESTION %d---------------------------------------------------------\n\n\n", correctAnswers + 1); // Printing question number at the top
	printf("\t\t\t\tPrize Money Won:\t\t₹%s\n",prizeMoney + correctAnswers); /* Printing the money won */
	printf("\t\t\t\tCorrect Answer:\t\t\t₹%s\n", prizeMoney + correctAnswers + 1); /* Printing the money that will be won on giving the correct answer */
	printf("\t\t\t\tWrong Answer:\t\t\t₹%s\n", prizeMoney  + currentLevel); /* Printing the money that the contestant will win ultimately if the question is answered incorrectly */
	printf("\t\t\t\tAvailable Lifelines:\t\t"); 
	display_Lifelines(); // to print the lifelines available
    
}



/* Function to display the lifelines available */
void display_Lifelines() {

	if (fiftyFifty == 1) // Checking if 50-50 is available
		printf("Fifty fity\t");
	
	if (flipQues == 1) // Checking if flip the question is available
		printf("Flip the Question\t");
		
	printf("\n\n\n\n");
		
}



/* Function to display the question with the options and subsequent instructions */
void display(struct questions *p, int *i) {

	system("clear"); /*clear output screen*/
	status(); // To display the current position of the contestant
	
	// Printing the question 
	printf ( "\t\t\t\t%s\n", p->q);
	
	//Displaying the options
	display_Options(p);
	
	// Instructions to the contestant to give their response
	printf("\t\t\t\tTo answer the question, type the letter corresponding to the option and press enter\n");
	printf("\t\t\t\tIf you want a lifeline, type L and press enter\n");
	printf("\t\t\t\tTo quit the game, type Q and press enter\n");
	printf("\t\t\t\tTo view the rules, type R and press enter\n\n");

	validate_Response(i); // Calling the validate_Response() function to act on user input         
    
}



/* Function to display options on the screen. If the arguments op1 and op2 are not null, it means that they have been called from 50-50 lifeline. Hence the function displays only two options corresponding to op1 and op2 if they are non-empty else prints all the four options */
void display_Options(struct questions *p) {

	if ( op1 == '\0') // op1='\0' implies that op2 = '\0'
		printf("\t\t\t\tA: %s\n\t\t\t\tB: %s\n\t\t\t\tC: %s\n\t\t\t\tD: %s", p->A, p->B, p->C, p->D);
		
	else {
	
		if(op1 == 'A' || op2 == 'A')
			printf("\t\t\t\tA: %s\n", p->A);
			
		if(op1 == 'B' || op2 == 'B')
			printf("\t\t\t\tB: %s\n", p->B);
			
		if(op1 == 'C' || op2 == 'C')
			printf("\t\t\t\tC: %s\n", p->C);
			
		if(op1 == 'D' || op2 == 'D')
			printf("\t\t\t\tD: %s\n", p->D);
				
			
	}
	
	printf("\n\n\n\n");
}
	


/* Function to take user input in between questions to determine if they want to continue or quit */
void continue_Ahead() {
	
	scanf("%c", &next);	// taking user input
	
    	next = toupper(next);	// converting input to upper case, in case the input is 'q' for quitting	
	
}    



/* Function to take user input after the question is displayed on the screen */
void take_Input() {

	char c[1000]; // initializing a string in case the user accidently enters multiple characters

	scanf(" %s", c); // taking the input in a string
	
	//Loop that will ask for input until the user enters a single character as input
	while (c[1] != 0) {
		printf("\t\t\t\tInvalid Input. Try Again\t");
		scanf(" %s", c);
    	}
    	
    	userAnswer = toupper(c[0]); /* storing the capitalized character input in variable userAnswer so that inputs like a,b,c,d,r,q,l also work */
    	
}		
 
 
 
/* Function to act upon the user input obtained after displaying the question. The function argument is an integer pointer corresponding to index of array set and calls various functions according to input */
void validate_Response(int *i) {
	
	printf("\t\t\t\tEnter your decision here:\t");
	take_Input(); // taking user input
	
    	/* Checking if the user has entered some meaningful character or some other character */
    	if (appropriate_Input(userAnswer) == 0)
    	
    		do{
    			printf("\t\t\t\tInvalid input. Please try again\t");
    			take_Input();

               } while(appropriate_Input(userAnswer) == 0);
               
	// Running a switch control to perform required action as per input      
    	switch (userAnswer) {
    		
    		// if the user wants lifeline
    		case 'L':
    		 	activate_Lifelines(i); 
                      	break;
               
               // if the user wants to quit the game       
               case 'Q':
               	system("clear"); //clears the screen
                      	leave_Game(); 
                  	break;
               
               // if the user wants to view the rules       
               case 'R':
                  	rules();
                  	getchar(); // to absorb one 'Enter' press so that the rules page doesn't get bypassed
                  	continue_Ahead(); // for continue prompt
                  	display(set + *i, i); // display the question again 
                  	break;
               
               // if the user has entered A or B or C or D       
               default:
                  	check_Response(set + *i, i); 
                      
               }
}



/* Function to check if the input is appropriate(one of the meaningful characters) or not */
int appropriate_Input(char a){

	if((a >= 65 && a <= 68)||(a == 'Q')||(a == 'R')||(a == 'L'))
		return 1;
		
	else
		return 0;

}



/* Function to perform the required subsequent actions in case of the answer being correct and incorrect respectively*/
void check_Response(struct questions *p, int *i){

	printf("\n\t\t\t\t-----------------------------------------------------------------------------------------\n\n");

	// If the answer is correct
	if(check_Correct_Answer(userAnswer, *i) == 1) {
	
		correctAnswers++;	// Increasing the count of correct answers by one
		level_Update();	// Updating the milestone that has been crossed 	 
		
		(*i)+=2;		// Incrementing the quesion index by 2 (each level has two questions, one for flip the question)
		
		// If the user answers all the questions correctly		
		if (correctAnswers == 15)
			winner_Message();
			
		
		printf("\t\t\t\tGreat! Your answer is correct!\n");
		
		
		printf("\t\t\t\tYou have won ₹%s\n\n", prizeMoney + correctAnswers);
		
		//Case when a milestone has been attained
		if(correctAnswers == currentLevel) {
			printf("\t\t\t\tBravo!! You have crossed a milestone\n");
			printf("\t\t\t\tYou will now take home atleast ₹%s\n\n", prizeMoney + correctAnswers);
		}
			
		
		// Prompt asking the user whether to continue or quit	
		printf("\t\t\t\tPress Enter to continue. To quit, press 'Q':\t");
		getchar();
		continue_Ahead();
		
		// Case when the user wants to quit the game
		if(next == 'Q') {
			system("clear");
			leave_Game();
		}
        	
    	}
	
	// In the case that the answer is wrong
	else {
			
		printf("\n\t\t\t\tSorry! Your answer is incorrect\n");
		
		// Printing the correct answer
		printf("\n\t\t\t\tThe correct answer is : ");
		printf("%c. ", correct_Option(p));
		printf("%s\n", p->correct_answer);
		
		// Updating the number of correct answers to that of latest mailestone crossed
		correctAnswers = currentLevel;
		
		// Exiting the game
		leave_Game();
		
	}
}



/* Function to determine if the answer is correct or wrong taking the answer and question number as parameters */
int check_Correct_Answer(char ans, int qn){
	
	if(ans == correct_Option(set + qn)) // if the input option matches that of the correct answer
		return 1;
	else
		return 0;

}



/* Function that returns the character corresponding to the correct answer of the question index sent in as parameter. This function uses the strcmp() function of the string.h library to individually compare the string contained in each of the options with that of the correct answer and in case of match, returns that option character*/
char correct_Option(struct questions *p){

	if(strcmp(p->A, p->correct_answer) == 0)
		return 'A';
		
	else if(strcmp(p->B, p->correct_answer) == 0)
		return 'B';
		
	else if(strcmp(p->C, p->correct_answer) == 0)
		return 'C';
		
	else
		return 'D';
}



/* Function to show the available lifelines and call them on user prompt */
void activate_Lifelines(int *p) {
	
	printf("\n\n");
	
	// Printing different messages as per different scenarios regarding lifelines
	
	if ((fiftyFifty == 1) && (flipQues == 1))
		printf("\t\t\t\tBoth lifelines are available. Type F to flip the question. Type 5 to avail fifty-fifty. \n");
		
	else if (fiftyFifty == 1)
		printf("\t\t\t\tFifty fifty lifeline is available. Type 5 to avail fifty-fifty. \n");
		
	else if (flipQues == 1)
		printf("\t\t\t\tFlip the question is available. Type F to flip the question.\n");
		
	else {
		printf("\t\t\t\tNo lifeline is available\n");
		validate_Response(p);
		return;
	}
	
	printf("\t\t\t\tIf you don't want to avail any lifeline, type any other character and press Enter\n");
	
	call_Lifeline(p);
}



/* Function to take input regarding choice of lifelines and call them */
void call_Lifeline(int *p) {

	printf("\t\t\t\tEnter your response:\t");
	take_Input();
	
	// Switch case to act upon user input
	switch (userAnswer) {
	
		case '5':
			fifty_Fifty(set + *p, p);
			break;
			
		case 'F':
			flip_Question(p);
			break;
			
		default:
			validate_Response(p); // Going back if the user doesn't want a lifeline
			
	}
}

        

/* Function to check for and update the milestone count after every question is correctly answered */
void level_Update() {

	if(correctAnswers < 3)
		currentLevel = 0; // No milestone reached
		
	else if(correctAnswers < 8)
		currentLevel = 3;
		
	else if(correctAnswers < 12)
       	currentLevel = 8;
       
	else
		currentLevel = 12; // All milestones crossed
}



/* Function to apply the lifeline flip the question on user prompt */
void flip_Question(int *p) {

	// Checking if the lifeline has already been used up
	if(flipQues == 0) {
		printf("\t\t\t\tLifeline not available\n");
		call_Lifeline(p);
		return;
	}
	
	flipQues = 0;		// Updating the flag variable to 0, to denote that now the lifeline has been used up
	system("clear");	// Clear the screen
	
	op1 = '\0', op2 = '\0'; // Ensuring that all four options are printed even if the user has used this immediately after 50-50
	(*p)++;		// Going to the immediate next question, which is for flip the question lifeline
	display(set+ *p, p);	// Displaying the new question
    
}



/* Function to enable 50-50 lifeline */
void fifty_Fifty(struct questions *p, int *i) {

	// Checking if the lifeline has already been used up
	if(fiftyFifty == 0){
		printf("\t\t\t\tLifeline not available\n");
		call_Lifeline(i);
		return;
    	}
    	
    	op1 = correct_Option(set + *i); // Storing the correct option
    	int j = 0;
    	
    	srand(time(NULL)); // initialising the PRNG(Pseudo Random Number Generator) at a different starting point to ensure random output
    	do {
    		
    		op2 = random_Generate();	// Obtaining a randomly generated character out of A,B,C,D
    		
    		// Ensuring that the random character is not the correct option
    		if(op2 == op1)
    			continue;
    		
    		j++;
    		
    	} while( j < 1);
    	
    	fiftyFifty = 0;  // Updating the flag variable to 0, to denote that now the lifeline has been used up 
    	    	
    	system("clear"); // Clear the screen
    	
    	display(p, i); // Display the question again 
    	
    	// Setting the two 50-50 options back to null so that all four options are printed from next question onwards
    	op1 = '\0';
    	op2 = '\0';
}



/* Function to generate a random character out of 'A', 'B', 'C' or 'D' */
char random_Generate() {

	int num = (rand() % 4) + 1; 	//Generates an integer between 1 and 4, both inclusive
	char ch = num + 64;		//Transforms the random integer to random character between A and D
	return ch;
     
}

 
 
/* Function to exit the game when the user quits or gives an incorrect answer */ 
void leave_Game() {

	printf("\n\n\t\t\t\tThank you for playing\n\n");
	
	//Congratulating the user, if he/she has won some money
	if(correctAnswers != 0)
			printf("\t\t\t\tCongratulations!!!\n\n");
			
	printf("\t\t\t\tYou have won ₹%s\n\n\n", prizeMoney + correctAnswers);
	exit(0);
}   
    
    
    
/* Function to print a special message for the contestant who has answered all 15 questions */
void winner_Message() {

	system("clear");

	printf("\t\t\t\t----------------------------------------------------------------------------------------------\n\n\n");
	printf("\t\t\t\tCONGRATULATIONS!!!!! You have succesfully answered all the questions correctly!\n\n");
	printf("\t\t\t\tYOU ARE THE WINNER OF KBC!!!!!\n\n\n");
	printf("\t\t\t\tYOU HAVE WON ₹ 7 CRORE!!!\n\n\n\n");
	exit(1);
}
        
    


