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

void findMatches(string& a_wordBank, grid& a_puzzle);

int isInt(string a_prompt, int a_min, int a_max);


int main()
{
	int answer = 0;
	
	grid puzzle("puzzle15.txt");
	
	int numWords = 0;
	string wordBank = "wordlist.txt";
	
	
	
	cout << "Please enter a number: \n"<<
			"1. Insertion Sort \n"<<
			"2. Merge Sort \n"<<
			"3. Quick Sort \n"<<
			"4. Heap \n"<<
			"5. HashTable \n"<<
			"6. Print all matches \n"<<
			"7. Exit Program \n";
	
	answer=isInt("",1,6);

	
	
	if (answer < 5) {
		numWords = search(wordBank, puzzle, answer);
		
	}
	if (answer == 5) {
		numWords = searchHash(wordBank, puzzle);
	}
	
	if (answer == 6) {
		findMatches(wordBank, puzzle);
		return 0;
	}
	
	cout << "Total Words: " << numWords << endl;
	
}



void findMatches(string& a_wordBank, grid& a_puzzle) //pass word list and grid
{
	wordList myWordList;
	myWordList.readList(a_wordBank);
	vector<string> allStrings = a_puzzle.getStrings();
	
	int numWords = 0;
	myWordList.QuickSort(0, myWordList.getSize()-1);

	for (auto checkString : allStrings)
	{
		if (myWordList.lookUp(checkString))
		{
			cout << checkString << endl;
			numWords++;
		}
	}

	cout << "Total Matches: " << numWords << endl;
}


int search(string& a_wordBank, grid& a_puzzle, int a_type) {

	wordList myWordList(a_wordBank);
	
	vector<string> allStrings = a_puzzle.getStrings();
	
	int numWords = 0;
	int sortTimeint=0;
	int SearchTimeint = 0;
	
	auto sortStart = high_resolution_clock::now();
	auto sortStop = high_resolution_clock::now();
	
	
	switch(a_type)
	{
		case 1: //Insertion Sort
			sortStart = high_resolution_clock::now();
			myWordList.InerstionSort();
			sortStop = high_resolution_clock::now();
			break;
			
		case 2: //Merge Sort
			sortStart = high_resolution_clock::now();
			myWordList.MergeSort(0, myWordList.getSize()-1);
			sortStop = high_resolution_clock::now();
			break;
			
		case 3: //Quick Sort
			sortStart = high_resolution_clock::now();
			myWordList.QuickSort(0, myWordList.getSize()-1);
			sortStop = high_resolution_clock::now();
			break;
			
		case 4: //Heap Sort
			sortStart = high_resolution_clock::now();
			myWordList.HeapSort();
			sortStop = high_resolution_clock::now();
			break;
	}
	

	auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
	sortTimeint = sortTime.count();
	cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	
	
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
	int numWords = 0;
	
	vector<string> allStrings = a_puzzle.getStrings();
	
	auto sortStart = high_resolution_clock::now();
	hashTable<string> myHashTable(a_wordBank, 12289);
	auto sortStop = high_resolution_clock::now();
	// some numbers to try 701, 12289, 49157
	//myHashTable.printSizes();
	
	
	auto duration = duration_cast<microseconds>(sortStop - sortStart);
	cout << "Time taken by sorting: " << duration.count() << " microseconds" << endl;
	


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



int isInt(string a_prompt, int a_min, int a_max)
{
	int input=NULL;
	while((input<a_min) || (input>a_max))
	{
		cout << a_prompt;
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else break;
	}
	return input;
}