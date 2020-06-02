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

using namespace std;

template <typename T>
hashTable<T>::hashTable(string a_fileName, int a_tableSize):m_hashGroups(a_tableSize)
{
	m_hashTable.resize(a_tableSize);
	
	readfile(a_fileName);
	
	for(auto it=m_wordList.begin(); it<m_wordList.end();it++)
	{
		addItem(m_wordList[it]);
	}
}



template <typename T>
void hashTable<T>::readfile(string a_fileName) {
	ifstream read;
	string word;
	
	m_wordList.clear();

	read.open(a_fileName.c_str());

	while (getline(read, word)) {
		m_wordList.push_back(word);
	}
}

//template <typename T>
//void hashTable<T>::assign_size()
//{
//	m_hashGroups = m_wordList.size();
//	cout << "hash groups: " << m_hashGroups << endl;
//}
//
//template <typename T>
//void hashTable<T>::addvector() {
//	for (int i = 0; i < m_wordList.size(); i++) {
//		string word;
//		word = m_wordList[i];
//		hashFunction(word);
//	}
//}

template <typename T>
int hashTable<T>::hashFunction(string a_value)
{
	double hash = 0;
	int key;
	key = a_value.length();

	for (int i = 0; i < a_value.length(); i++)
	{
		hash += (int)a_value[i];
		cout << "hash=" << hash << endl;
	}
	
	int tempKey = int((hash * .618033));//.618033 = (sqrt(5)-1)/2
	tempKey = int(fmod(tempKey, 1));
	key = floor(m_hashGroups*tempKey);
		
	return key;
}


template <typename T>
void hashTable<T>::addItem(string a_newValue)
{
	int hashValue=hashFunction(a_newValue);
	m_hashTable[hashValue].push_back(a_newValue);
}

//template <typename T>
//void hashTable<T>::deleteItem(int a_index)
//{
//
//}

template <typename T>
bool hashTable<T>::inList(string a_checkValue)
{
	int hashValue=hashFunction(a_checkValue);
	
	for (auto it=m_hashTable[hashValue].begin();it<m_hashTable[hashValue].end();it++)
	{
		if (m_hashTable[hashValue][it]==a_checkValue)
			return true;
	}
	return false;
}

