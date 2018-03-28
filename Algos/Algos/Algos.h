#include <vector>
#include <fstream>
#include <time.h>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;


template <class T>
class Algos
{
public:
	int *myArr, myArrSize;

	Algos();

	/* Random array generator */
	vector<T> generateArray(int size, int max);

	/* Writes arrays to files */
	void recordArray(vector<T> arr);

	/* Writes Sort times to files */
	void recordTime(string name,vector<pair<int,float>>);

	/* Initializes myArr with the dataset with given size */
	void fetchArray(int arrSize);

	/* Sorting Algorithms */
	void MergeSort(T arr[], int l, int r);
	void SelectionSort(int arr[]);
	void InsertionSort(T arr[]);
	void BubbleSort(T arr[]);
	void QuickSort(T arr[],int low,int high);

protected:
	void Merge(T arr[], int l, int m, int r);	//Helper function for MergeSort
	int partition(T arr[], int low, int high);	//Helper function for QuickSort

};

