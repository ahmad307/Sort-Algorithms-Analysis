#include "Algos.h"


template <class T>
Algos<T>::Algos()
{
}

/* Generates a vector of random numbers of the given size */
template <class T>
vector<T> Algos<T>::generateArray(int size, int max)
{
	vector<T> arr(size);
	srand(time(NULL));	//Setting randomization seed
	for (int i = 0; i < size; i++)
	{
		//Generating random number less or equal to the max
		arr[i] = rand() % max + 1;
	}
	return arr;
}

/* Writing array to file */
template <class T>
void Algos<T>::recordArray(vector<T> arr)
{
	//Openning the file suiting the dataset
	ofstream dataFile;
	if (arr.size() <= 100000)
		dataFile.open("input_small.txt", ios::app);
	else
		dataFile.open("input_large.txt",ios::app);

	//Recording the array on the file
	dataFile << arr.size() << endl;
	for (int i = 0; i < arr.size(); i++)	
		dataFile << arr[i] << " ";
	dataFile << endl;

	dataFile.close();
}

/* Saves sort time in a file */
template <class T>
void Algos<T>::recordTime(string name, vector<pair<int,float>> times)
{
	ofstream dataFile;
	dataFile.open("sortResults_milliseconds.txt", ios::app);

	dataFile << name << " ";
	for (int i = 0; i < times.size(); i++)	dataFile << fixed << setprecision(7) << times[i].second << " ";
	dataFile << endl;

	dataFile.close();
}

template <class T>
void Algos<T>::fetchArray(int arrSize)
{
	myArrSize = arrSize;
	myArr = new T[myArrSize];

	ifstream dataFile;
	if (myArrSize <= 100000)
		dataFile.open("input_small.txt");
	else
		dataFile.open("input_large.txt");

	//Searching for the required array
	while (true)
	{
		int tempSize;
		dataFile >> tempSize;

		if (tempSize == myArrSize)
		{
			for (int i = 0; i < myArrSize; i++)
				dataFile >> myArr[i];
			return;
		}
		else
		{
			string s;
			getline(dataFile, s);
		}
	}
	dataFile.close();
}

/* Sorting Algorithms */
template <class T>
void Algos<T>::MergeSort(T arr[], int l, int r)
{
	if (r - l <= 0)   return;

	int mid = (l + r) / 2;
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);

	Merge(arr, l, mid, r);
}

template <class T>
void Algos<T>::Merge(T arr[], int l, int m, int r)
{
	//Copying two halves into new auxillary arrays
	int size1 = m - l + 1, size2 = r - m;
	int *arr1 = new int[size1], *arr2 = new int[size2];
	for (int i = 0; i<size1; i++)   arr1[i] = arr[i + l];
	for (int i = 0; i<size2; i++)   arr2[i] = arr[i + m + 1];

	//Merging the two halves
	int j1 = 0, j2 = 0;
	for (int i = l; i <= r; i++)
	{
		if ((arr1[j1] < arr2[j2] && j1<size1) || j2 >= size2)
		{
			arr[i] = arr1[j1];
			j1++;
		}
		else {
			arr[i] = arr2[j2];
			j2++;
		}
	}
}

template <class T>
void Algos<T>::QuickSort(T arr[], int low, int high)
{
	if (low >= high)    return;

	int split = partition(arr, low, high);
	QuickSort(arr, low, split - 1);
	QuickSort(arr, split + 1, high);
}

//Helper function for QuickSort
template <class T>
int Algos<T>::partition(T arr[], int low, int high)
{
	int pivot = arr[high], i = low - 1;
	for (int j = low; j<high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

template <class T>
void Algos<T>::SelectionSort(int arr[])
{
	for (int i = 0; i < myArrSize; i++)
	{
		//Traversing the array to find Min element
		int min = arr[i], index = i;
		for (int j = i; j < myArrSize; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		swap(arr[index], arr[i]);	//Putting the Min element into place
	}
}

template <class T>
void Algos<T>::InsertionSort(T arr[])
{
	for (int i = 1; i < myArrSize; i++)
	{
		int counter = i;
		while (arr[counter]<arr[counter - 1])
		{
			swap(arr[counter], arr[counter - 1]);
			counter--;
			if (counter <= 0) break;
		}
	}
}

template <class T>
void Algos<T>::BubbleSort(T arr[])
{
	for (int i = 0; i < myArrSize - 1; i++)
	{
		for (int j = 0; j < myArrSize - i -1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <class T>
Algos<T>::~Algos()
{
}
