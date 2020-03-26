#include <iostream>

using namespace std;


/




void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;

}


char partition(char arr[], char low, char high)
{
	char pivot = arr[high];
	char i = (low - 1);

	for (char j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */

void quickSort(char arr[], char low, char high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		char pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


/* Function to print an array */
void printArray(char arr[], char size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code 
int main()
{
	char arr[] = { 'A','V','S','D','D','Z' };
	char n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

