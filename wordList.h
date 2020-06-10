//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_WORDLIST_H
#define PROJECT3_WORDLIST_H

//(a) stores the word list in a vector
//(b) a function to read the words from the wordlist file
//(c) an overloaded output operator to print the word list
//(d) functions that sort the words using
//											1) insertionSort
//											2) quickSort
//											3) mergeSort
//											4) heapSort (using a heap object)
//(e) a function to handle word lookups using binary search
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class wordList
{
private:
    
    vector<string> m_wordList; // word list stored in a vector
    

public:
    
    wordList()= default; // default constructor
    
    wordList(string a_fileName){readList(a_fileName);}; //constructor that immediately calls the readFile
    
    void readList(string a_fileName); // reads words from the text file
    
    vector<string> getList() {return m_wordList;}; // returns the list
    int getSize() const {return m_wordList.size();}; //returns the size of the list
    string getAt(int a_index) const {return m_wordList.at(a_index);}; //returns a particular element from list
    
    
    void InerstionSort(); // search via Insertion Sort
    
    void MergeSort(int p, int q); // search via MergeSort
    void Merge(int p, int q, int r); // merge function for Merge sort
    
    void QuickSort(int p, int q); // search via Quick Sort
    int Partition(int p, int h); // partition for quick sort
    
    void HeapSort(bool a_isMax=true);   // search via HeapSort, will use maxHeap by default
    									// or minHeap if argument is provided as false
    
    bool lookUp(string a_word); //Uses Binary Search to check is argument exists in word list
    							//returns true if word is found
    
    void printList() const; //function that formats the printing of the list
    
    friend ostream& operator << (ostream cout, const wordList& a_list); // overload print function, calls printList
};


#endif //PROJECT3_WORDLIST_H
