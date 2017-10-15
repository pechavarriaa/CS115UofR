//  ========================================================================== 
// | Assignment Two : SortAndSearch
// |
// | Author : PABLO ECHAVARRIA
// | Language : C++
// | Instructor : MUSTAKIM AL HELAL
// | Due Date : SUNDAY, OCTOBER, 15, 2017 AT 11:59PM
//  +--------------------------------------------------------------------------
// | Description :     Using functions, write a C++ program:
// |                   1. that sorts a list of natural numbers using the bubble sort algorithm described in project
// |                       4, page 557, chapter 9, sixth edition (or project 4, page 483, chapter 9, fifth edition)
// |                   2. and then looks for a particular number using the binary search algorithm defined in
// |                      project 12, page 560, chapter 9, sixth edition (or project 12, page 486, chapter 9, fifth edition).    
// |
// | Input :  5
// |          2 3 1 4 5
// |          3
// |          Y
// | 
// | Output : 
// |          1 2 3 4 5
// |          Number 3 is found at position 3
// |
//  ============================================================================
/*The bubble sort is another technique for sorting an array. A bubble sort
  compares adjacent array elements and exchanges their values if they’re
  out of order. In this way, the smaller values “bubble” to the top of the
  array (toward element 0), while the larger values sink to the bottom of
  the array. After the first pass of a bubble sort, the last array element is in
  the correct position; after the second pass, the last two elements are
  correct, and so on. Thus, after each pass, the unsorted portion of the
  array contains one less element. Write and test a function that
  implements this sorting method.*/

//headers
#include <iostream>//cin and cout
#include <algorithm>//swap(int,int)

using namespace std;//avoid using std::

const int ARR_SIZE = 1000;//max size of array

class readNumbers {//class to read numbers
public:
  void readIntegers();//function to read integers
protected:
  int numbers[ARR_SIZE];//array to hold numbers
  int arrSize;//size of array
};

class bubbleSort :public readNumbers {//function to sort and sear
public:
  void bSort();//function to do bubble sort
  void bPrint();//function to print
  int bSearch(int searchNumber);//binary search
  bubbleSort(int n);//constructor for initialize arrSize from base class readIntegers
};
//constructor
bubbleSort::bubbleSort(int n)
{
  arrSize = n;//initialize arrSize with value from user
}
//bubble sort implementation
void bubbleSort::bSort()
{
  int length = arrSize;//used for not modify arrSize

  bool isSorted = true;//boolean to check if is still sorted or not
  while (isSorted) {
    isSorted = false;
    for (int i = 0; i < length - 1; i++)//iterate trough
      {
	if (numbers[i] > numbers[i + 1])
	  {
	    swap(numbers[i], numbers[i + 1]);//swap numbers if they are not in order
	    isSorted = true;//if there is a swap we have to continue sorting
	  }
      }
    length--;//as last number is in order, decrease list number
  }
}
//print numbers
void bubbleSort::bPrint()
{
  cout << "Numbers sorted in ascending order :" << endl;
  for (int i = 0; i < arrSize; i++)//iterate trough list and print numbers
    cout << numbers[i] << " ";
  cout << endl;
}
//Binary Search
int bubbleSort::bSearch(int searchNumber)
{
  //binary search parameters
  int beggining = 0;
  int middle = 0;
  int end = arrSize;

  while (beggining <= end)
    {
      middle = (beggining + end) / 2;
      if (numbers[middle] == searchNumber)
	{
	  return middle + 1;//return index for number
	}
      else if (searchNumber > numbers[middle])
	{
	  beggining = middle + 1;//check in the right side of the half
	}
      else if (searchNumber < numbers[middle])
	{
	  end = middle - 1;//check in the left side of the half
	}
    }
  return -1;//number not found

}
//read input from user
void readNumbers::readIntegers()
{

  //read how many integers are going to be sorted
  cout << "Enter the natural numbers to sort:" << endl;
  for (int i = 0; i < arrSize; i++)
    {
      cin >> numbers[i];
      //read input values to sort
    }
}

int main()
{
  char wContinue = 'Y';//while user continue using the program
  while (wContinue == 'Y' || wContinue == 'y')
    {
      int sizeArr;
      cout << "Enter the number of naturals:";//ask for list size
      cin >> sizeArr;
      while (!(sizeArr > 0 && sizeArr < 1000))//ask for valid number
	{
	  cout << "Plese provide an integer from 1 to 999." << endl;
	  cin >> sizeArr;
	  cout << endl;
	}
      
      bubbleSort numbers(sizeArr);//create bubbleSort type with constructor
      numbers.readIntegers();//read numbers from user
      numbers.bSort();//sort numbers
      numbers.bPrint();//print in order numbers
      
      cout << "Enter the number to search: ";//ask for search numbers
      int numberToSearch = 0;
      cin >> numberToSearch;
      int indexNumber = numbers.bSearch(numberToSearch);//index number that function returns

      if (indexNumber == -1)//number not found
	{
	  cout << "Number " << numberToSearch << " does not exist!" << endl;
	}
      else//number at X position
	{
	  cout << "Number " << numberToSearch << " is found at position:" << indexNumber << endl;
	}
      
      cout << endl << "Do you want to continue[Y / N]:";//ask user to continue
      cin >> wContinue;
      cout << endl;
      
      while (wContinue != 'Y' && wContinue != 'y' && wContinue != 'N' && wContinue != 'n')
	{
	  cout << "Plese type \"Y\" or \"N\"" << endl;
	  cin >> wContinue;
	  cout << endl;
	}
      //wait for valid answer
    }
  cout << "Good Bye!" << endl;//end of program
  return 0;
}
/*
  6
  8 3 6 2 7 1
*/
