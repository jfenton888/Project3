//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "hashTable.h"
#include "hashTable.cpp"
#include "grid.h"
#include "heap.h"
#include "matrix.h"
#include "matrix.cpp"
#include "wordList.h"
#include "reverse_iterate.h"

using namespace std;
using namespace std::chrono;
//global functions



//global function search(int) which reads the name of the grid file from the keyboard
//and prints out all words from the word list that can be found in the grid. The function
//should also print out the CPU time to sort the words, the CPU time to find the words, and
//the total time. The integer parameter is used to select the sorting algorithm used.

int search(string& a_wordBank, grid& a_puzzle, int a_type);

int searchHash(string& a_wordBank, grid& a_puzzle);


int main()
{
	int answer = 0;
	
	//grid puzzle("input15.txt");
	grid puzzle("puzzle50.txt");
	
	int numWords = 0;
	string wordBank = "wordlist2.txt";
	
	
	
	cout << "Please enter a number: \n"<<
			"1. Insertion Sort \n"<<
			"2. Merge Sort \n"<<
			"3. Quick Sort \n"<<
			"4. Heap \n"<<
			"5. HashTable \n"<<
			"6. Print all matches \n";
	cin >> answer;

	
	

	if (answer < 5) {
		numWords = search(wordBank, puzzle, answer);
		
	}
	if (answer == 5) {
		numWords = searchHash(wordBank, puzzle);
	}
	
	cout << "Total Words: " << numWords << endl;
	
}

/*
void findMatches(string& a_wordBank, grid& a_puzzle) //pass word list and grid
{
	int totalMatches=search(a_wordBank, a_puzzle,1);
	cout<<"Total Words: "<<totalMatches<<endl;
}



int search(string& a_wordBank, grid& a_puzzle)
{
	auto sortStart = high_resolution_clock::now();
	hashTable<string> myHashTable(a_wordBank, 701);
	auto sortStop = high_resolution_clock::now();
	vector<string> allStrings = a_puzzle.getStrings();
	auto duration = duration_cast<microseconds>(sortStop - sortStart);
	cout << "Time taken by sorting: " << duration.count() << " microseconds" << endl;
	int numWords = 0;


	auto searchStart = high_resolution_clock::now();
	for (int check = 0; check < allStrings.size(); check++)
	{
		if (myHashTable.inList(allStrings[check]))
		{
			cout << allStrings[check] << endl;
			numWords++;
		}
	}
	auto searchStop = high_resolution_clock::now();
	auto searchTime = duration_cast<microseconds>(searchStop - searchStart);
	cout << "Time taken by search: " << searchTime.count() << " microseconds" << endl;
	int totalTime = searchTime.count() + duration.count();
	cout << "Total time taken: " << totalTime << " microseconds" << endl;
	return numWords;
}




int searchHeap(string& a_wordBank, grid& a_puzzle) {

}*/



int search(string& a_wordBank, grid& a_puzzle, int a_type) {

	wordList myWordList(a_wordBank);
	
	vector<string> allStrings = a_puzzle.getStrings();
	int numWords = 0;
	int sortTimeint=0;
	int SearchTimeint = 0;
	
	//Insertion Sort
	if (a_type == 1)
	{
		auto sortStart = high_resolution_clock::now();
		myWordList.InerstionSort();
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}

	//Merge Sort
	if (a_type == 2)
	{
		auto sortStart = high_resolution_clock::now();
		
		myWordList.MergeSort(0, myWordList.getSize()-1);
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}

	//Quick Sort
	if (a_type == 3)
	{
		auto sortStart = high_resolution_clock::now();
		
		myWordList.QuickSort(0, myWordList.getSize()-1);
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}
	//Heap Sort
	if (a_type == 4)
	{
		auto sortStart = high_resolution_clock::now();
		myWordList.HeapSort();
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}
	

	auto searchStart = high_resolution_clock::now();
	
	
	for (auto checkString:allStrings)
	{
		if (myWordList.lookUp(checkString))
		{
			cout << checkString << endl;
			numWords++;
		}
	}
	
	
	auto searchStop = high_resolution_clock::now();
	auto searchTime = duration_cast<microseconds>(searchStop - searchStart);
	cout << "Time taken by search: " << searchTime.count() << " microseconds" << endl;
	SearchTimeint = searchTime.count();
	int totalTime = SearchTimeint + sortTimeint;
	cout << "Total time taken: " << totalTime << " microseconds" << endl;
	
	
	
	return numWords;
}


int searchHash(string& a_wordBank, grid& a_puzzle)
{
	auto sortStart = high_resolution_clock::now();
	
	hashTable<string> myHashTable(a_wordBank, 49157);
	vector<string> allStrings = a_puzzle.getStrings();
	
	auto sortStop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(sortStop - sortStart);
	cout << "Time taken by sorting: " << duration.count() << " microseconds" << endl;
	int numWords = 0;


	auto searchStart = high_resolution_clock::now();
	
	
	for (auto checkString:allStrings)
	{
		if (myHashTable.inList(checkString))
		{
			cout << checkString << endl;
			numWords++;
		}
	}
	
	
	auto searchStop = high_resolution_clock::now();
	auto searchTime = duration_cast<microseconds>(searchStop - searchStart);
	cout << "Time taken by search: " << searchTime.count() << " microseconds" << endl;
	
	int totalTime = searchTime.count() + duration.count();
	cout << "Total time taken: " << totalTime << " microseconds" << endl;
	
	return numWords;
}
