# Sort-Algorithms-Analysis
My implementation of some of the well-known sorting algorithms, with calculation of each algorithm's runtime with different datasets, and then analysing obtained data using *Matplotlib* Python library.

The repository is divided as follows:

## Visual Studio Project
The Visual Studio Project consists of different folders, the most important is *Algos* containing 3 main files:
* Algos.h
* Algos.cpp
* Main.cpp

With all member functions declaration in *Algos.h* and definition in *Algos.cpp*. *Main.cpp* is where Algos class function are used to obtain data sets from two file:
* input_large.txt
* input_small.txt

and sorting runtimes saved in:
* sortResults.txt
* sortResults_milliseconds.txt

## AlgosTimePlots.py
* ```AlgosTimePlots.py``` uses *Matplotlib* library to create plots for each sorting algorithm runtime against several data sets.

* ```AlgosTimePlots.py``` fetches data from the previously created file ```sortResults_milliseconds.txt``` and saves the created charts in the same directory.