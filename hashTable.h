//
// Project by Jack Fenton
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
//template class hashTable<T> that stores objects in a hash table of type vector<vector<T> >, and which includes:
//
//(a) functions addItem(), deleteItem(), and inList()
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
	int m_hashGroups=0;
	vector<string> m_wordList;
	
	vector<vector<T>>  m_hashTable;
	
public:
	hashTable()= default;
	
	hashTable(string a_fileName, int a_tableSize=701);
	
	void readfile(string a_fileName);
	//void assign_size();
	int hashFunction(string a_value);
	//void addvector();
	//bool isEmpty() const;
	
	
	void addItem(string a_newValue);
	
	//void deleteItem(int a_index);
	
	bool inList(string a_checkValue);
	
	
};


#endif //PROJECT3_HASHTABLE_H








