//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_HASHTABLE_H
#define PROJECT3_HASHTABLE_H

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


public:

	void addItem();

	void deleteItem();
	
	void inList();



};


#endif //PROJECT3_HASHTABLE_H








