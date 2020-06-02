//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include <iostream>
#include <cstring>
#include<vector>
#include "hashTable.h"

using namespace std;

template<typename T>
void hashTable<T>::readfile() {
	ifstream read;
	string word;
	string name = "wordlist.txt";
	wordlist.clear();

	read.open(name.c_str());

	while (getline(read, word)) {
		wordlist.push_back(word);
	}
}

template<typename T>
void hashTable<T>::assign_size()
{
	m_hashGroups = wordlist.size();
	cout << "hash groups: " << m_hashGroups << endl;
	hashstorage.resize(m_hashGroups);
}

template<typename T>
void hashTable<T>::addvector() {
	for (int i = 0; i < wordlist.size(); i++) {
		string word; 
		int hashkey;
		word = wordlist[i];
		hashkey = hashFunction(word);
		additem(hashkey, word);
	}
}

template<typename T>
int hashTable<T>::hashFunction(string a_word)
{
	double hash = 0;
	int key;
	key = a_word.length();

	for (int i = 0; i < a_word.length(); i++)
	{
		hash += (int)a_word[i];
		cout << "hash=" << hash << endl;
	}
	
	int thing = (hash * .618033);//.618033 = (sqrt(5)-1)/2
	thing = fmod(thing, 1);
	key = floor(m_hashGroups*thing);
		
	return key;
}

template<typename T>
void hashTable<T>::additem(int a_hash, string a_value){
	const unsigned int hashkey = a_hash;
	vector<T> hash = {hashkey, a_value };
	hashstorage.push_back(hash);
}
