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

//Functions Prototypes
void ReadArray(array[]);
void BubbleSort(array[]);

int main() 
{
	int sizeArray = 0;
	cout << "Enter the number of naturals:" << endl;
	cin >> sizeArray;
	cout << "Enter the natural numbers to sort:" << endl;
	readArray( array[], sizeArray);
	
	return 0;
}
void readArray(int array[], int & arrSize)
{
	int array[arrSize];
	while(arrSize--)
	cin >> array[arrSize]; //Inserting the values into an array, 
}
void bubbleSort(array[])
{
	
}
