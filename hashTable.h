//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_HASHTABLE_H
#define PROJECT3_HASHTABLE_H

#include <iostream>
#include <cstring>
#include<vector>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

//
//template class hashTable<T> that stores objects in a hash table of type vector<vector<T>>, and which includes:
//
//(a) functions addItem() and inList()
//(b) function hash() which returns the hash value for an item Since the Hash Table
//			will be used to look up words, you can copy the unsorted words into
//			the hash table, and then the hashTable::inList function can be used
//			to look up words. You can make findMatches a tem- plate function that
//			can be passed data structures of different types.
//


template <typename T=string>
class hashTable
{
private:
	int m_hashGroups; //number of indices in the hash table, each of which contains a vector of varying length
	
	vector<string> m_wordList;
	
	vector<vector<T>> m_hashTable;
	
public:
	hashTable():m_hashGroups(0){};
	
	hashTable(string a_fileName, int a_tableSize=701);  //creates hash table with specified size
														//fills the hash table using the strings from the file
	
	
	void readfile(string a_fileName); // fills m_wordList with words from file

	int hashFunction(string a_value); // hash function calculates an index for the hash table
									  // based on the value of the argument provided
									  // the same value will always produce the same result in a given run
	
	void addItem(string a_newValue); // adds given argument to the table, location calculated using hashFunction
	
	void deleteItem(vector<T>& a_hash, int a_place);
	
	bool inList(string a_checkValue); // returns boolean for if the given argument is found in the table
	
	void printSizes(); //prints the size of the vector at each hash value, used to check the hashFunction
	
	vector<T>& operator[] (int a_index); // index operator
	
};


#endif //PROJECT3_HASHTABLE_H








