#include "Algos.cpp"
#include <iomanip>

using namespace std;

int main()
{
	//Algos<int> A(100000);
	
	/* Populating files with random arrays (Done) */
	/*
	int sizes[7] = { 100,500,1000,100000,500000,1000000,10000000 };
	for (int i = 0; i < 7; i++)
		A.recordArray(A.generateArray(sizes[i], 100));
	*/
	
	
	/*vector< Algos<int> > dataSets;	 // Vector of classes each determining a dataset size 
	//Initializing the array with different data sets
	dataSets.push_back(Algos<int>(100)), dataSets.push_back(Algos<int>(500)), dataSets.push_back(Algos<int>(1000)),
		dataSets.push_back(Algos<int>(100000)), dataSets.push_back(500000), dataSets.push_back(Algos<int>(1000000)), dataSets.push_back(Algos<int>(100000000));
		*/

	/*prev calculation
	Algos<int> B;
	int dataSets[7] = { 100,500,1000,100000,500000,1000000,100000000 };
	for (int i = 0; i < 7; i++)
	{
		//Populating class vector with required data set
		B.fetchArray(dataSets[i]);

		cout << "Data Set: " << B.myArrSize << endl;

		float time;
		chrono::steady_clock::time_point start;
		chrono::steady_clock::time_point end;

		//Calculating MergeSort time
		start = chrono::steady_clock::now();
		B.MergeSort(B.myArr, 0, B.myArrSize - 1);		
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		cout << "\t" << "MergeSort: " << fixed << setprecision(6) << time << " seconds" << endl;

		//Calculating QuickSort time
		B.fetchArray(dataSets[i]);	//Insures fetching an unsorted dataset
		start = chrono::steady_clock::now();
		B.QuickSort(B.myArr, 0, B.myArrSize - 1);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		cout << "\t" << "QuickSort: " << fixed << setprecision(6) << time << " seconds" << endl;

		//Calculating Selection sort time
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.SelectionSort(B.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		cout << "\t" << "SelectionSort: " <<fixed<<setprecision(6) << time << " seconds" << endl;

		//Calculating InsertionSort time
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.InsertionSort(B.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		cout << "\t" << "InsertionSort: " << fixed << setprecision(6) << time << " seconds" << endl;

		//Calculating BubbleSort time
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.BubbleSort(B.myArr);
		end = chrono::steady_clock::now();

		time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		cout << "\t" << "BubbleSort: " << fixed << setprecision(6) << time << " seconds" << endl;

	}*/

	Algos<int> B;
	int dataSets[7] = { 100,500,1000,100000,500000,1000000,100000000 };
	vector<pair<int, float>> times;
	float time;
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;

	//calculating MergeSort times
	cout << "Merge Sort" << endl;
	for (int i = 0; i < 6; i++)
	{
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.MergeSort(B.myArr, 0, B.myArrSize - 1);
		end = chrono::steady_clock::now();

		//time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSets[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSets[i],time });
	}
	B.recordTime("Merge", times);

	//calculating QuickSort times
	times.clear();
	cout << "Quick Sort" << endl;
	for (int i = 0; i < 6; i++)
	{
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.QuickSort(B.myArr, 0, B.myArrSize - 1);
		end = chrono::steady_clock::now();

		//time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSets[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSets[i],time });
	}
	B.recordTime("Quick", times);
	
	//calculating SelectionSort times
	times.clear();
	cout << "Selection Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.SelectionSort(B.myArr);
		end = chrono::steady_clock::now();

		//time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSets[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSets[i],time });
	}
	B.recordTime("Selection", times);

	//calculating InsertionSort times
	times.clear();
	cout << "Insertion Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.InsertionSort(B.myArr);
		end = chrono::steady_clock::now();

		//time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSets[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSets[i],time });
	}
	B.recordTime("Insertion", times);
	//calculating BubbleSort times
	times.clear();
	cout << "Bubble Sort" << endl;
	for (int i = 0; i < 5; i++)
	{
		B.fetchArray(dataSets[i]);
		start = chrono::steady_clock::now();
		B.BubbleSort(B.myArr);
		end = chrono::steady_clock::now();

		//time = chrono::duration_cast<chrono::duration<float>>(end - start).count();
		time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		cout << "\t" << dataSets[i] << " : " << fixed << setprecision(6) << time << " seconds" << endl;

		times.push_back({ dataSets[i],time });
	}
	B.recordTime("Bubble", times);

	/*temporary test
	A.fetchArray();
	//A.SelectionSort(A.myArr);
	//A.MergeSort(A.myArr, 0, A.myArrSize - 1);
	//A.BubbleSort(A.myArr);
	//A.InsertionSort(A.myArr);

	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	A.SelectionSort(A.myArr);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	//for (int i = 0; i < A.myArrSize; i++)	cout << A.myArr[i] << " ";  //Printing the sorted array
	float sTime = chrono::duration_cast<chrono::duration<float>>(end - start).count();
	int msTime =  chrono::duration_cast<chrono::milliseconds>(end - start).count();

	cout << sTime << " " << msTime << endl;
	for (int i = 0; i < A.myArrSize; i++)	cout << A.myArr[i] << " ";
	*/
	return 0;
}