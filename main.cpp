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

#include "hashTable.h"
#include "hashTable.cpp"
#include "grid.h"
#include "heap.h"
#include "matrix.h"
#include "matrix.cpp"
#include "wordList.h"

using namespace std;

//global functions


//global function findMatches() that is passed the word list and the grid as parameters
//and which prints out all words that can be found in the grid.
void findMatches() //pass word list and grid
{
	return;
}

//global function search(int) which reads the name of the grid file from the keyboard
//and prints out all words from the word list that can be found in the grid. The function
//should also print out the CPU time to sort the words, the CPU time to find the words, and
//the total time. The integer parameter is used to select the sorting algorithm used.
int search(string a_wordBank, string a_puzzle)
{


}





int main()
{

	grid myPuzzle("puzzle10.txt");
	
	//cout<<myPuzzle;
	
	//cout<<myPuzzle.getChar(-2,0);
	
	vector<string> allStrings=myPuzzle.getStrings();
	
	for(int it=0; it<allStrings.size();it++)
		cout<<allStrings[it]<<endl;


	//hashTable<string> myHashTable("wordlist.txt", 701);
	//cout << myHashTable.inList("livid");


}

