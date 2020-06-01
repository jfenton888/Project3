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



class hashTable
{
private:
static const int m_hashGroups=1;

vector<pair<int, string>> m_table[m_hashGroups];

public:

void assign_size(vector<string>  a_dict);

bool isEmpty() const;

int hashFunction(int a_key);

void addItem(int a_key, string a_value);

void addVector(vector<string> a_dict);

void deleteItem(int a_key);

int inList(int a_key);

void printTable();

};



#endif //PROJECT3_HASHTABLE_H








