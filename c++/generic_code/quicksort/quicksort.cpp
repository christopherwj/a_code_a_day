#include <iostream>

using namespace std;



void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;

}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
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
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);
 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code 
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5, 4, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}




/*

scratch code from Larry NyHoff data strcutures textbook:

template <typename ElementType>
void Split(ElementType x[], int first, int last, int& pos)
{
	ElementType pivot = x[first];
	int left = first;
	right = last;

	while (left < rint)
	{
		while (x[right] > pivot)
			right--;
		while (left < right && x[left] <= pivot)
			left++;
		if (left < right)
			swap(x[left], x[right]);
	} //end of searches, place pivot in correct position
	pos = right;
	x[first] = x[pos];
	x[pos] = pivot;
}


template <typename ElementType>
void Quicksort(ElementType x[], int first, int last)
{
	int pos;

	if (first < last)
	{
		//split into two sub lists
		Split(x, first, last, pos);
		//sort left sublist
		Quicksort(x, first, pos - 1);
		//sort right sublist
		Quicksort(x, pos + 1, last);
	}
	//else list has 0 or 1 element and needs no sorting
}
*/
