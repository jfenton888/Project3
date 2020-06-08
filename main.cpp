//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include <iostream>
#include <cstring>
#include<vector>
#include<fstream>
#include<string>
#include<chrono>

#include "hashTable.h"
#include "hashTable.cpp"
#include "grid.h"
#include "heap.h"
#include "matrix.h"
#include "matrix.cpp"
#include "wordList.h"

using namespace std;
using namespace std::chrono;
//global functions


//global function findMatches() that is passed the word list and the grid as parameters
//and which prints out all words that can be found in the grid.
void findMatches(string& a_wordBank, grid& a_puzzle); //pass word list and grid


//global function search(int) which reads the name of the grid file from the keyboard
//and prints out all words from the word list that can be found in the grid. The function
//should also print out the CPU time to sort the words, the CPU time to find the words, and
//the total time. The integer parameter is used to select the sorting algorithm used.
int search(string& a_wordBank, grid& a_puzzle);




int main()
{
	
	int answer = 0;
	cout << "Please enter a number:" << endl; 
	cout << "1. Insertions Sort" << endl; 
	cout << "2. Merge Sort" << endl;
	cout << "3. Quick Sort" << endl;
	cout << "4. Heap" << endl;
	cout << "5. HashTable" << endl;
	cout << "6. Print all matches" << endl;
	cin >> answer;

	grid a_puzzle("input15.txt");

	//findMatches("wordlist2.txt", a_puzzle);
	int numWords = 0;
	string a_wordBank = "15x15s.txt";

	if (answer < 4) {
		numWords = search(a_wordBank, a_puzzle, answer);
		
	}

	if (answer == 4) {
		numWords = searchHash(a_wordBank, a_puzzle);
	}
	
	cout << "Total Words: " << numWords << endl;
	
}


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
/*
int searchHeap(string& a_wordBank, grid& a_puzzle) {

}*/

int search(string& a_wordBank, grid& a_puzzle, int a_type) {

	wordList mywordlist;
	mywordlist.readList(a_wordBank);
	vector<string> allStrings = a_puzzle.getStrings();
	int numWords = 0;
	int sortTimeint=0;
	int SearchTimeint = 0;
	
	if (a_type == 1) {
		auto sortStart = high_resolution_clock::now();
		mywordlist.InerstionSort();
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
		
	}

	if (a_type == 2) {
		auto sortStart = high_resolution_clock::now();
		int para = mywordlist.getrange();
		mywordlist.MergeSort(0, para);
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}

	
	if (a_type == 3) {
		auto sortStart = high_resolution_clock::now();
		int para = mywordlist.getrange();
		mywordlist.QuickSort(0, para);
		auto sortStop = high_resolution_clock::now();
		auto sortTime = duration_cast<microseconds>(sortStop - sortStart);
		sortTimeint = sortTime.count();
		cout << "Time taken by sorting: " << sortTime.count() << " microseconds" << endl;
	}
	

	auto searchStart = high_resolution_clock::now();
	for (int check = 0; check < allStrings.size(); check++)
	{
		string word = allStrings[check];
		if (mywordlist.lookUp(word)==true)
		{
			cout << word << endl;
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
	
	hashTable<string> myHashTable(a_wordBank, 701);
	vector<string> allStrings = a_puzzle.getStrings();
	
	auto sortStop = high_resolution_clock::now();
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
	cout << "Total time taken:" << totalTime << " microseconds" << endl;
	
	return numWords;
}
