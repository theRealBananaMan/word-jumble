#include <iostream>
#include <string>
#include <cstdlib>
//used for time/ generating random numbers

#include <ctime>

using namespace std;

int main(void)
{

	//get random seed for random number generation
	srand(time(NULL));


	//array of 4 rows and 2 columns, holds the answers and hints to the easy level
	string easy[4][2] = { { "bird", "Animal with wings and a beak" },
	{ "hand", "Five fingers and a palm"},
	{ "walk", "Right foot then left foot"} ,
	{ "water", "Drink a gallon everyday"} };

	//array of 4 rows and 2 columns, holds the answers and hints to the medium level
	string medium[4][2] = { { "apple", "Hint: It is a red fruit"},
	{ "knife", "Sharp tool"},
	{ "bottle", "Hint: It holds drinks"},
	{ "computer", "Hint: Mac and Dell"} };

	//array of 4 rows and 2 columns, holds the answers and hints to the hard level
	string hard[4][2] = { { "thesaurus", "Big book of concepts"},
	{ "petroleum", "Harvested from rocks"},
	{ "distillery", "Alcohol manufacturing"},
	{ "carbonation", "Fizzy drinks"} };

	//initial variable calling and assigning
	int difficulty;
	int level = 1;
	int x = 0;
	int y = 0;
	int i = 0;
	int temp;
	int num1;
	int num2;
	int attempt = 1;
	int sizeOfWord;
	int again;

	string hint;
	string original;
	string jumble;
	string guess;

	char placeHolder;

	bool gameOver = false;


	//while the game is has not been quit, do the following...
	while (gameOver == false)
	{
	//Begin outputting the game content to the console window
	cout << "WELCOME TO WORD JUMBLE" << endl;
	cout << "\nENTER THE DESIRED DIFFICULTY" << endl << "1. EASY" << endl << "2. MEDIUM" << endl << "3. HARD\n" << endl;
	cout << "SET DIFFICULTY TO:	";
	//gets value from user, sets value to variable difficulty
	cin >> difficulty;
	//clears the current displayed content out of the window
	system("CLS");
	//runs specific case depending on level of difficulty input by the user ("1" being easiest)
	switch (difficulty)
	{

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user enters the value "1" run code for the easy level...
	case 1:
	cout << "YOU HAVE SELECTED EASY" << endl;
	cout << "YOU WILL HAVE 3 ATTEMPTS TO UN-JUMBLE ALL OF THE WORDS" << endl;
	if (level == 1)
	{
	//pulls value from array and set it to variable jumble
	jumble = easy[x][y];
	original = easy[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = easy[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}

	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 2)
	{
	//pulls value from array and set it to variable jumble
	jumble = easy[x][y];
	original = easy[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = easy[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 3)
	{
	//pulls value from array and set it to variable jumble
	jumble = easy[x][y];
	original = easy[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = easy[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 4)
	{
	//pulls value from array and set it to variable jumble
	jumble = easy[x][y];
	original = easy[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = easy[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl << "YOU HAVE SUCCESSFULLY COMPLETED ALL LEVELS FOR EASY" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU WON WITH " << temp << "/3 CHANCES REMAINING!" << endl;
	//resets the variables in case the user wants to play again
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	}
	break;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user enters the value "2" do the following...
	case 2:
	cout << "YOU HAVE SELECTED MEDIUM" << endl;
	cout << "YOU WILL HAVE 3 ATTEMPTS TO UN-JUMBLE ALL OF THE WORDS" << endl;
	if (level == 1)
	{
	//pulls value from array and set it to variable jumble
	jumble = medium[x][y];
	original = medium[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = medium[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 2)
	{
	//pulls value from array and set it to variable jumble
	jumble = medium[x][y];
	original = medium[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = medium[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 3)
	{
	//pulls value from array and set it to variable jumble
	jumble = medium[x][y];
	original = medium[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = medium[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 4)
	{
	//pulls value from array and set it to variable jumble
	jumble = medium[x][y];
	original = medium[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = medium[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl << "YOU HAVE SUCCESSFULLY COMPLETED ALL LEVELS FOR MEDIUM" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU WON WITH " << temp << "/3 CHANCES REMAINING!" << endl;
	//resets the variables in case the user wants to play again
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	}
	break;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user enters the value "3" do the following...
	case 3:
	cout << "YOU HAVE SELECTED HARD" << endl;
	cout << "YOU WILL HAVE 3 ATTEMPTS TO UN-JUMBLE ALL OF THE WORDS" << endl;
	if (level == 1)
	{
	//pulls value from array and set it to variable jumble
	jumble = hard[x][y];
	original = hard[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = hard[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 2)
	{
	//pulls value from array and set it to variable jumble
	jumble = hard[x][y];
	original = hard[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = hard[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 3)
	{
	//pulls value from array and set it to variable jumble
	jumble = hard[x][y];
	original = hard[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = hard[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	//keeps track of the number of wrong attempt
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	//sets the level to the next level
	level++;
	y--;
	}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user answers the previous level correctly, the following level will run...
	if (level == 4)
	{
	//pulls value from array and set it to variable jumble
	jumble = hard[x][y];
	original = hard[x][y];
	y++;
	//pulls string from array and sets it to variable hint
	hint = hard[x][y];
	x++;
	//gets the length of the current word and sets it to variable sizeOfWord
	sizeOfWord = jumble.size();

	//jumble's the word based on the words length
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	//jumbles the word again if it comes out the same as the original
	if (jumble == original)
	{
	for (i = 0; i < sizeOfWord; i++)
	{
	//sets a random number between 0 and the length of the word to num1
	num1 = (rand() % sizeOfWord);
	//sets a random number between 0 and the length of the word to num2
	num2 = (rand() % sizeOfWord);
	//saves the first character that will be changed in a temporary space
	placeHolder = jumble[num1];
	//changes the first number to the second number
	jumble[num1] = jumble[num2];
	//gets the first character, saved in the temp space, and sets it to the second character
	jumble[num2] = placeHolder;
	}
	}
	//prints the final jumbled word to the console window
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//gets user's guess for the jumbled word
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	//if the user guesses incorrectly do the following...
	while (guess != original && attempt < 3)
	{
	attempt++;
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT, TRY AGAIN..." << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU HAVE " << temp << "/3 CHANCES REMAINING" << endl;
	cout << "GUESS THE WORD:  " << jumble << endl << "TYPE 'hint' FOR A HINT" << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;

	if (guess == "hint")
	{
	system("CLS");
	cout << "HINT: " << hint << endl;
	cout << "GUESS THE WORD:  " << jumble << endl;
	cout << "\nGUESS: ";
	//assigns the user's guess to the variable guess
	cin >> guess;
	}
	}
	if (guess != original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//requests the user to input the correct answer
	cout << "'" << guess << "' IS INCORRECT... GAME OVER" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU USED " << attempt << "/3 CHANCES" << endl;
	cout << "THE WORD WAS " << original << endl;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}

	}
	//if the user guesses the correct answer for the jumbled word do the following...
	if (guess == original && attempt < 4)
	{
	//clears the content in the console window
	system("CLS");
	//Alerts the user they answered correctly
	cout << "CORRECT! GREAT JOB!" << endl << "YOU HAVE SUCCESSFULLY COMPLETED ALL LEVELS FOR HARD" << endl;
	//gets the number of attempt the user has remaining
	temp = (4 - attempt);
	cout << "YOU WON WITH " << temp << "/3 CHANCES REMAINING!" << endl;
	//resets the variables in case the user wants to play again
	level = 1;
	x = 0;
	y = 0;
	attempt = 1;
	//asks the player if they want to play again
	cout << "\nPLAY AGAIN..?" << endl << "1. YES" << endl << "2. NO" << endl;
	cin >> again;
	if (again == 1)
	{
	system("CLS");
	gameOver = false;
	}
	if (again == 2)
	{
	gameOver = true;
	}
	}
	}
	break;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if the user enters anything other than "1", "2" or "3", do the following...
	default:
	gameOver = false;
	}
	}
	//keeps the console window open so the final output can be viewed before continuing out of the program
	system("pause");
	return 0;
}