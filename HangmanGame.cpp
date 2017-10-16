//  ========================================================================== 
// | Assignment Two : HangmanGame
// |
// | Author : PABLO ECHAVARRIA
// | Language : C++
// | Instructor : MUSTAKIM AL HELAL
// | Due Date : SUNDAY, OCTOBER, 15, 2017 AT 11:59PM
//  +--------------------------------------------------------------------------
// | Description :     Project 10, page 485, chapter 9, fifth edition.
// |					The word to be guessed is stored in an external file
// |
// | Input and Output :  Set difficulty of game[easy/normal/hard]:easy
// |						Guess a Letter(You Have 5 tries left) : e
// |						Right!.Word so far is : ***e*
// |
// |						Guess a Letter(You Have 5 tries left) : s
// |						Wrong!Try Again.Word so far is : ***e*
// |
// |						Guess a Letter(You Have 4 tries left) : p
// |						Wrong!Try Again.Word so far is : ***e*
// |
// |						Guess a Letter(You Have 3 tries left) : t
// |						Right!. Word so far is : *t*e*
// |
// |						Guess a Letter(You Have 3 tries left) : i
// |						Wrong! Try Again.Word so far is : *t*e*
// |
// |						Guess a Letter(You Have 2 tries left) : p
// |						Wrong! Try Again.Word so far is : *t*e*
// |
// |						Guess a Letter(You Have 1 tries left) : e
// |						Wrong!Try Again.Game Over : (
// |						Word->other
// | 
// |
//  ============================================================================
#include <iostream>//cin and cout
#include <fstream>//iostream
#include <string>//strings use
#include <cstdlib> //srand,rand 
#include <ctime>//time(NULL) for rand
#include <algorithm>//min(int,int)

using namespace std;

const int ALPHABET = 26; //Letters in the dictionary

class fStreaming
{
public:
	void openFile();//open file function
	void closeFile();//close file function
	void countWords();//count the number of words in the file
protected:
	ifstream wordsFile;//ifstream to work with file of words
	int numOfWords;//know the number of words to later generate random word
};
class randNumbers :public fStreaming
{
public:
	void getWord();//randomly get a word
protected:
	string word;//store the word
};
class process : public randNumbers
{
public:
	void playWithUser();//simulation of game	
	void setAttempts();//generate attempts
	process(string gameLevel);//ask difficulty 
	~process();
protected:
	int attempts;//num of attempts left
	string level;
	int strLetters[ALPHABET] = { 0 };// Array for counting letters
};
//Open file implementation, where the words are stored
void fStreaming::openFile()
{
	wordsFile.open("external_file.txt");
}
//Close file implementation, where the words are stored
void fStreaming::closeFile()
{
	wordsFile.close();
}
// Function to know the number of words
void fStreaming::countWords()
{
	string temp;
	numOfWords = 0;
	while (wordsFile >> temp)//Iterate through all the words by reading them in a temporal string
	{
		numOfWords++; //Count number of words
	}
}
//get word from file
void randNumbers::getWord()
{
	srand(time(NULL));//Initialize random seed
	int randWord = 0;
	randWord = rand() % numOfWords;//Getting a random index of the words list
	int index = 0;
	string temp;
	while (wordsFile >> temp)
	{
		if (index == randWord)//Find random word index
		{
			word = temp;//Save random word
		}
		index++;
	}
}
//constructor initialized with game level
process::process(string gameLevel)
{
	level = gameLevel;
}

process::~process() {

}
//initialize attempts variable
void process::setAttempts()
{
	for (int i = 0; i < word.length(); i++)
	{
		strLetters[int(word[i] - 'a')]++;
	}
	int differentLetters = 0; //Quantity of different letters
	for (int i = 0; i < ALPHABET; i++)
	{
		if (strLetters[i] > 0)
		{
			differentLetters++;//increment number of different letters
		}
	}

	//update level difficulty based on user input
	if (level == "hard")
	{
		attempts = differentLetters;
	}
	else if (level == "normal")
	{
		attempts = (differentLetters * 3) / 2;
	}
	else if (level == "easy")
	{
		attempts = min(differentLetters, 15);
	}
}
void process::playWithUser()
{
	bool indexGuessded[110] = { false };//help to print * asterisk
	char readChar;//read from user
	int lettersNotGuessed = word.length();//letters that have not been guessed
	while (attempts > 0 && lettersNotGuessed > 0)//attempts left and letters missing
	{
		bool checkAnswer = false;//check if user guessed right
		cout << "Guess a Letter (You Have " << attempts << " tries left): ";
		cin >> readChar;
		for (int i = 0; i < word.length(); i++)
		{
			//check if match and that has not been guessed before
			if (word[i] == readChar && indexGuessded[i] == false)
			{
				indexGuessded[i] = true;//check index
				checkAnswer = true;//user guessed well
				lettersNotGuessed--;//one less 
			}
		}
		if (checkAnswer)//check if user guessed
			cout << "Right!. ";
		else
		{
			cout << "Wrong! Try Again. ";
			attempts--;
			//user has one attempt left
		}
		if (attempts == 0 || lettersNotGuessed == 0)//avoid printing word is so far...
			continue;
		cout << "Word so far is: ";
		for (int i = 0; i < word.length(); i++)
		{
			if (indexGuessded[i])
				cout << word[i];
			else
				cout << "*";
		}
		cout << endl << endl;
	}

	//give feedback to player
	if (attempts == 0)
		cout << "Game Over :(" << endl;

	else if (lettersNotGuessed == 0)
		cout << "Congratulations :) you Guessed the word!!" << endl;

	cout << "Word -> " << word << endl;

}
int main()
{
	char kPlaying='y';//read char from user 
	while (kPlaying =='y')
	{
		//ask difficulty to user
		string difficulty = "";
		cout << "Set difficulty of game[easy/normal/hard]:";
		cin >> difficulty;
		//wait for valid input if necessary
		while (difficulty != "easy" && difficulty != "normal" && difficulty != "hard")
		{
			cout << "Please provide a valid Game difficulty" << endl << "[easy/normal/hard] in lowercase" << endl;
			cin >> difficulty;
			cout << endl;
		}
		cout << endl;
		//create object 
		process game(difficulty);

		game.openFile();//open file to count words
		game.countWords();
		game.closeFile();//close file

		game.openFile();//open file to get word 
		game.getWord();//randomly get a word knowing the amount of words
		game.closeFile();//close file

		game.setAttempts();//set attempts based on difficulty
		game.playWithUser();//simulate game

		//ask user to continue playing
		cout << "Do you want to continue playing?[y/n]: ";
		cin >> kPlaying;
		while (kPlaying != 'y' && kPlaying != 'n')
		{
			cout << "Please provide a valid answer [y/n] (lowercase)" << endl;
			cin >> kPlaying;
			cout << endl;
			//wait until user enter a valid answer
		}
	}
	cout << "Good Bye, thanks for Playing!" << endl;
	return 0;
}
