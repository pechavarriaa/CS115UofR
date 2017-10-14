/*The bubble sort is another technique for sorting an array. A bubble sort
  compares adjacent array elements and exchanges their values if they’re
  out of order. In this way, the smaller values “bubble” to the top of the
  array (toward element 0), while the larger values sink to the bottom of
  the array. After the first pass of a bubble sort, the last array element is in
  the correct position; after the second pass, the last two elements are
  correct, and so on. Thus, after each pass, the unsorted portion of the
  array contains one less element. Write and test a function that 
  implements this sorting method.*/

#include <iostream>
using namespace std;

const int ARR_SIZE = 1000;

class readNumbers{
public:
  void readIntegers();
protected:
  int numbers[ARR_SIZE];
  int arrSize;
}

class bubbleSort private readNumbers{
public:
  void sort();
  int search(int searchNumber);
  BubbleSort();
};

/*
BubbleSort::BubbleSort()
{
  
}
*/

void readNumbers::readIntegers()
{
    cout << "Enter the number of naturals:" << endl;
    cin>>arrSize;
    //read how many integers are going to be sorted
    cout << "Enter the natural numbers to sort:" << endl;
    for(int i =0;i<arrSize;i++)
      {
	cin>>numbers[i];
	//read input values to sort
      }
}

int main() 
{

  bubbleSort numbers;
  numbers.readIntegers();
  return 0;
}
