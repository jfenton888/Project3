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
	
	cout<<"m_wordList.size()="<<m_wordList.size()<<endl;
	for(int it=0; it<m_wordList.size();it++)
	{
		addItem(m_wordList.at(it));
	}
}


// non-constant version: provides general access to matrix elements
template <typename T>
vector<T>& hashTable<T>::operator[] (int a_index)
{
	if (a_index < 0 || a_index >= m_hashGroups)
		// throw range error - include error file
		return m_wordList[a_index];
}




template <typename T>
void hashTable<T>::readfile(string a_fileName) {
	ifstream read;
	string word;
	int numWords;
	string fileName="wordlist.txt";
	m_wordList.clear();

	read.open(fileName.c_str());

	while (getline(read, word)) {
		m_wordList.push_back(word);
		numWords++;
	}
	cout<<numWords<<" words in list \n";
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
	}
	
	key = floor(m_hashGroups*(fmod(hash*.618033,1)));
		
	return key;
}


template <typename T>
void hashTable<T>::addItem(string a_newValue)
{
	int hashValue=hashFunction(a_newValue);
	cout<<a_newValue<<" at: "<<hashValue<<endl;
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
	cout<<a_checkValue<<" being checked at: "<<hashValue<<endl;
	
	for (int it=0;it<m_hashTable[hashValue].size();it++)
	{
		if ((m_hashTable.at(hashValue)).at(it)==a_checkValue)
		{
			cout<<"Exists \n";
			return true;
		}
	}
	return false;
}

