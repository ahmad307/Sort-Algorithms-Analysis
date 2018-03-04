#include "Algos.cpp"
#include <iomanip>

using namespace std;

int main()
{	
	/* Populating files with random arrays (Done) */
	/*
	int sizes[7] = { 100,500,1000,100000,500000,1000000,10000000 };
	for (int i = 0; i < 7; i++)
		A.recordArray(A.generateArray(sizes[i], 100));
	*/
	

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

	return 0;
}