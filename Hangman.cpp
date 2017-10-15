#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
class fStreaming{
public:
  void openFile();//open file function
  void closeFile();//close file function
  void countWords();//count the number of words in the file
protected:
  ifstream wordsFile;//ifstream to work with file of words
  int numOfWords;//know the number of words to later generate random word
};
class randNumbers:public fStreaming {
public:
  void getWord();//randomly get a word
protected:
  string word;//store the word
};
class process : public randNumbers {
public:
  void playWithUser();//simulation of game
  process(string gameLevel);//ask difficulty of game and create variable
protected:
  int attempts;//num of attempts left
};
int main(){


  return 0;
}
