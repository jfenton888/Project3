//
// Project by Jack Fenton
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
//											1) insertionSort,
//											2) quickSort, and
//											3) mergeSort
//(e) a function to handle word lookups using binary search
//

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

class wordList
{
private:
    
    std::vector<std::string> wlist; // wordlist stored in a vector
    

public:
    
    //wordList(); // constructor
    void readList(); // reads words from the text file
    std::vector<std::string> getList(); // get the list
    
    friend std::ostream& operator << (std::ostream os, const wordList& list); // overload print funcion
    
    void InerstionSort(); // search via Insertion Sort
    void MergeSort(int p, int q); // search via MergeSort
    void Merge(int p, int q, int r); // merge function for mergersort
    void QuickSort(int p, int q); // search via Quick Sort
    int Partition(int p, int h); // partition for quick sort
    void HeapSort(); // search via HeapSort
    bool lookUp(std::string word); // looks up to see if word exists

};


#endif //PROJECT3_WORDLIST_H
