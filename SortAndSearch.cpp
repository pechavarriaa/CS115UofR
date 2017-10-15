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
#include <algorithm>

using namespace std;

const int ARR_SIZE = 1000;

class readNumbers {
public:
	void readIntegers();
protected:
	int numbers[ARR_SIZE];
	int arrSize;
};

class bubbleSort :public readNumbers {
public:
	void bSort();
	void bPrint();
	//int search(int searchNumber);
	bubbleSort(int n);
};


bubbleSort::bubbleSort(int n)
{
	//Constructor
	arrSize = n;
}

void bubbleSort::bSort()
{
	int length = 0;
	length = arrSize;
	bool isSorted = true;
	while (isSorted) {
		isSorted = false;
		for (int i = 0; i < length; i++)
		{
			if (numbers[i] > numbers[i+1])
			{
				swap(numbers[i], numbers[i + 1]);
				isSorted = true;
			}
		}
		length--;
	}
}

void bubbleSort::bPrint()
{
	for (int i = 0; i < arrSize; i++)
		cout << numbers[i] << " ";
	cout << endl;
}
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
	int sizeArr;
	cout << "Enter the number of naturals:" << endl;
	cin >> sizeArr;
	bubbleSort numbers(sizeArr);
	numbers.readIntegers();
	numbers.bSort();
	numbers.bPrint();
	//return 0;
}
/*
6
8 3 6 2 7 1
*/
