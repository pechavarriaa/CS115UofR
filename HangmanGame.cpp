#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
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
	process(string gameLevel);//ask difficulty of game and create variable
protected:
	int attempts;//num of attempts left
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
		if (index == randWord)//FInd random word index
		{
			word = temp;
		}
		index++;
	}
}
int main() {
	return 0;
}
