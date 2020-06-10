//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
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
	
	for(auto word:m_wordList)
		addItem(word);
	
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
void hashTable<T>::readfile(string a_fileName)
{
	string word="NULL";
	m_wordList.clear();
	
	ifstream file (a_fileName);
	if (file.is_open())
	{
		while (getline(file, word))
			m_wordList.push_back(word);
	}
	else
		cout << "Unable to open file \n";
	file.close();
}


template <typename T>
int hashTable<T>::hashFunction(string a_value)
{
	long double hash = 0;
	int key;
	key = a_value.length();

	for (int i = 0; i < a_value.length(); i++)
		hash += (int)a_value[i]*pow(3,i);
	
	long double A = (powf(5,0.5)-1)/2;
	key = floor(m_hashGroups*(fmod(hash*A,1)));
	
	//if(key==0) cout<<a_value<<" is "<<hash<<endl;
	return key;
}


template <typename T>
void hashTable<T>::addItem(string a_newValue)
{
	int hashValue=hashFunction(a_newValue);
	m_hashTable[hashValue].push_back(a_newValue);
}

template <typename T>
void hashTable<T>::deleteItem(vector<T>& a_hash, int a_place)
{
	a_hash.erase(a_hash.begin() + a_place);
}

template <typename T>
void::hashTable<T>::printSizes()
{
	int totSize=0;
	for(auto hash:m_hashTable)
	{
		cout << hash.size() << endl;
		totSize+=hash.size();
	}
	cout<<endl<<totSize<<endl;
}


template <typename T>
bool hashTable<T>::inList(string a_checkValue)
{
	int hashValue=hashFunction(a_checkValue);
	
	for (int it=0;it<m_hashTable[hashValue].size();it++)
	{
		if ((m_hashTable.at(hashValue)).at(it)==a_checkValue)
		{
			//cout<< m_hashTable[hashValue].size()<<endl;
			deleteItem(m_hashTable[hashValue], it);
			
			return true;
		}
		
	}
	return false;
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