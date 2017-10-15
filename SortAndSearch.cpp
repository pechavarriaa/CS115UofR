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
	int bSearch(int searchNumber);
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
		for (int i = 0; i < length - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
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
	cout << "Numbers sorted in ascending order :" << endl;
	for (int i = 0; i < arrSize; i++)
		cout << numbers[i] << " ";
	cout << endl;
}

int bubbleSort::bSearch(int searchNumber)
{
	int beggining = 0;
	int middle = 0;
	int end = 0;
	end = arrSize;

	while (beggining <= end)
	{
		middle = (beggining + end) / 2;
		if (numbers[middle] == searchNumber)
		{
			return middle + 1;
		}
		else if (searchNumber > numbers[middle])
		{
			beggining = middle + 1;
		}
		else if (searchNumber < numbers[middle])
		{
			end = middle - 1;
		}
	}
	return -1;

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
	char wContinue = 'Y';
	while (wContinue == 'Y' || wContinue == 'y')
	{
		int sizeArr;
		cout << "Enter the number of naturals:";
		cin >> sizeArr;
		while (!(sizeArr > 0 && sizeArr < 1000))
		{
			cout << "Plese provide an integer from 1 to 999." << endl;
			cin >> sizeArr;
			cout << endl;
		}
		bubbleSort numbers(sizeArr);
		numbers.readIntegers();
		numbers.bSort();
		numbers.bPrint();
		cout << "Enter the number to search: ";
		int numberToSearch = 0;
		cin >> numberToSearch;
		int indexNumber = numbers.bSearch(numberToSearch);

		if (indexNumber == -1)
		{
			cout << "Number " << numberToSearch << " does not exist!" << endl;
		}
		else
		{
			cout << "Number " << numberToSearch << " is found at position:" << indexNumber << endl;
		}
		cout << endl << "Do you want to continue[Y / N]:";
		cin >> wContinue;
		cout << endl;
		while (wContinue != 'Y' && wContinue != 'y' && wContinue != 'N' && wContinue != 'n')
		{
			cout << "Plese type \"Y\" or \"N\"" << endl;
			cin >> wContinue;
			cout << endl;
		}
	}
	cout << "Good Bye" << endl;
	return 0;
}
