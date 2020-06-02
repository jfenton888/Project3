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

void hashTable::readfile() {
	ifstream read;
	string word;
	string name = "wordlist.txt";
	wordlist.clear();

	read.open(name.c_str());

	while (getline(read, word)) {
		wordlist.push_back(word);
	}
}

void hashTable::assign_size()
{
	m_hashGroups = wordlist.size();
	cout << "hash groups: " << m_hashGroups << endl;
}

void hashTable::addvector() {
	for (int i = 0; i < wordlist.size(); i++) {
		string word; 
		word = wordlist[i];
		hashFunction(word);
	}
}

int hashTable::hashFunction(string a_word)
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
