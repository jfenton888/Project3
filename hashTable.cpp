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

void hashTable::assign_size(vector<string> m_dict)
{
	static const int m_hashGroups = m_dict.size();
}

bool hashTable::isEmpty() const
{
	int sum = 0;
	for (int i = 0; i < m_hashGroups; i++) {
		sum += m_table[i].size();
	}
	
	if (!sum) {
		return true;
	}
	return false;
}

int hashTable::hashFunction(int a_key)
{
	return a_key % m_hashGroups;
}

void hashTable::addItem(int a_key, string a_value)
{
	int hashValue = hashFunction(a_key);
	auto& cell = m_table[hashValue];
	auto Itr = begin(cell);
	bool keyExists = false;
	for (; Itr != end(cell); Itr++)
	{
		if (Itr->first == a_key)
		{
			keyExists = true;
			Itr->second = a_value;
			cout << "key exists. value replaced." << endl;
			break;
		}
	}
	
	if (!keyExists)
		cell.emplace_back(a_key, a_value);
	
	return;
}


void hashTable::addVector(vector<string> a_dict)
{
	for (int i = 0; i < a_dict.size(); i++)
		addItem(i, a_dict[i]);
}



void hashTable::deleteItem(int a_key)
{
	int hashValue = hashFunction(a_key);
	auto& cell = m_table[hashValue];
	auto Itr = begin(cell);
	bool keyExists = false;
	for (; Itr != end(cell); Itr++)
	{
		if (Itr->first == a_key)
		{
			keyExists = true;
			Itr = cell.erase(Itr);
			cout << "Item Removed" << endl;
			break;
		}
	}
	
	if (!keyExists)
		cout << "Item not found. Pair has not been removed." << endl;
	
}

int hashTable::inList(string a_word) {
	for (int i = 0; i < m_hashGroups; i++) {
		int hashValue = hashFunction(i);
		auto& cell = m_table[hashValue];
		auto Itr = begin(cell);
		bool keyExists = false;
		for (; Itr != end(cell); Itr++) {
			if (Itr->second == a_word) {
				int value = Itr->first;
				return value;
				break;
			}
		}

	}
}

void hashTable::printTable()
{
	for (int i = 0; i < m_hashGroups; i++)
	{
		if (m_table[i].size() == 0)
			continue;
		
		auto Itr = m_table[i].begin();
		for (; Itr != m_table[i].end(); Itr++)
			cout << "Hash Table Key:" << Itr->first << "Value: " << Itr->second << endl;
	}
	return;
}


