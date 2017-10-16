#include <iostream>//cin and cout
#include <fstream>//iostream
#include <string>//strings use
#include <cstdlib> //srand,rand 
#include <ctime>//time(NULL) for rand

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
			differentLetters++;
		}
	}

	if (level == "hard")
	{
		attempts = differentLetters;
	}
	else if (level == "normal")
	{
		attempts = (differentLetters * 3)/2;
	}
	else if (level == "easy")
	{
		attempts = min(differentLetters,15);
	}
}
void process::playWithUser()
{
  bool indexGuessded[110]={false};//help to print * asterisk
  char readChar;//read from user
  int lettersNotGuessed = word.length();//letters that have not been guessed
	while(attempts>0 && lettersNotGuessed>0)//attempts left and letters missing
	{
		bool checkAnswer=false;//check if user guessed right
		cout<<"Guess a Letter (You Have "<<attempts<<" tries left): ";
		cin>>readChar;
		for(int i =0;i<word.length();i++)
		{
			//check if match and that has not been guessed before
			if(word[i]==readChar && indexGuessded[i]==false)
			{
				indexGuessded[i]=true;//check index
				checkAnswer = true;//user guessed well
				lettersNotGuessed--;//one less 
			}
		}
		if(checkAnswer)//check if user guessed
			cout<<"Right!. "<<endl;	
		else
		{
			cout<<"Wrong! Try Again. ";
			attempts--;
			//user has one attempt left
		}
		if(attempts==0 || lettersNotGuessed==0)//avoid printing word is so far...
			continue;
		cout<<"Word so far is: ";
		for(int i =0;i<word.length();i++)
		{
			if(indexGuessded[i])
			cout<<word[i];
			else
			cout<<"*";
		}
		cout<<endl<<endl;
	}

	//give feedback to player
	if(attempts==0)
		cout<<"Game Over :("<<endl;

	else if(lettersNotGuessed==0)
		cout<<"Congratulations :) you Guessed the word!!"<<endl;
	
		cout<<"Word -> "<<word<<endl;

}
int main()
{
	string difficulty;
	cout << "Set difficulty of game[easy/normal/hard]:";
	cin >> difficulty;
	cout << endl;

	process game(difficulty);
	
	game.openFile();
	game.countWords();
	game.closeFile();

	game.openFile();
	game.getWord();
	game.closeFile();

	game.setAttempts();
	game.playWithUser();
	return 0;
}