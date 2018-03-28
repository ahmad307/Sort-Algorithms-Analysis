#include "Algos.cpp"
#include <iomanip>

using namespace std;

int main()
{	
	/* Populating files with random arrays (Done) */
	/*
	Algos<int> A;
	int sizes[7] = { 100,500,1000,100000,500000,1000000,10000000 };
	for (int i = 0; i < 7; i++)
		A.recordArray(A.generateArray(sizes[i], 100));
	*/
	

	Algos<int> timeCalculation;
	int dataSetsSizes[7] = { 100,500,1000,100000,500000,1000000,100000000 };

	/* Stores the runtime for each data size ; {Size, Runtime} */
	vector<pair<int, float>> times;		

	/* Start and end clocks to measure each sort's runtime */
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;
	float time;

	/*

	With each sorting Algorithm, fetchArray() is firstly called for the class to grab the array with the required size
	on each iteration from the data files.
	A 'start' clock is set and the required sorting algorithm is called, then an 'end' clock is set and their difference
	is saved in the variable 'time'.

	The time taken for data set is displayed on each iteration and saved in the vector 'times'. 
	After the loop finishes, 'times' that now contains all the sort algorithm's data, is sent to the function 'recordTime'
	for the data to be saved in the .txt files.

	*/

	//calculating MergeSort times
	cout << "Merge Sort" << endl;
	for (int i = 0; i < 6; i++)
	{
		timeCalculation.fetchArray(dataSetsSizes[i]);
		start = chrono::steady_clock::now();
		timeCalculation.MergeSort(timeCalculation.myArr, 0, timeCalculation.myArrSize - 1);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSetsSizes[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSetsSizes[i],time });
	}
	timeCalculation.recordTime("Merge", times);

	//calculating QuickSort times
	times.clear();
	cout << "Quick Sort" << endl;
	for (int i = 0; i < 6; i++)
	{
		timeCalculation.fetchArray(dataSetsSizes[i]);
		start = chrono::steady_clock::now();
		timeCalculation.QuickSort(timeCalculation.myArr, 0, timeCalculation.myArrSize - 1);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSetsSizes[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSetsSizes[i],time });
	}
	timeCalculation.recordTime("Quick", times);
	
	//calculating SelectionSort times
	times.clear();
	cout << "Selection Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		timeCalculation.fetchArray(dataSetsSizes[i]);
		start = chrono::steady_clock::now();
		timeCalculation.SelectionSort(timeCalculation.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSetsSizes[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSetsSizes[i],time });
	}
	timeCalculation.recordTime("Selection", times);

	//calculating InsertionSort times
	times.clear();
	cout << "Insertion Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		timeCalculation.fetchArray(dataSetsSizes[i]);
		start = chrono::steady_clock::now();
		timeCalculation.InsertionSort(timeCalculation.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSetsSizes[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSetsSizes[i],time });
	}
	timeCalculation.recordTime("Insertion", times);

	//calculating BubbleSort times
	times.clear();
	cout << "Bubble Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		timeCalculation.fetchArray(dataSetsSizes[i]);
		start = chrono::steady_clock::now();
		timeCalculation.BubbleSort(timeCalculation.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSetsSizes[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSetsSizes[i],time });
	}
	timeCalculation.recordTime("Bubble", times);

	return 0;
}