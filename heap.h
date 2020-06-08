//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_HEAP_H
#define PROJECT3_HEAP_H


//
//template class heap<T> that stores objects in a heap of type vector<T>, and which includes:
//
//(a) functions parent(int), left(int), right(int), and getItem(int n)
//                which returns the nth item in the heap.
//(b) for a max-heap, functions initialize MaxHeap(), maxHeapify(), and buildMaxHeap().
//(c) the equivalent functions for a min-heap. You can implement the
//            max-heap and min-heap data structures within the same
//            class and convert the stored data into a min- or max-heap
//            by calling the appropriate member functions.
//(d) function heapSort()
//

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "heap.h"

using namespace std;

template <typename T>

class heap
{
private:
	
	//vector<T>* m_list;

public:
    
    heap(); //constructor
	
	void heapSort(vector<T>& a_list, string a_type="max"); // creates max heap, sorts it (when given unsorted list)
	
	
	void buildMaxHeap(vector<T>& a_list); // turns unsorted vector into max heap
    void maxHeapify(vector<T>& a_list, int a_heapSize, int i); // max heapifies node i (children = max heaps)
    
	
	void buildMinHeap(vector<T>& a_list); // turns unsorted vector into min heap
    void minHeapify(vector<T>& a_list, int a_heapSize, int i); // min heapifies node i (children = min heaps)
    
    
    
        
    
    int parent(int i) {return int(floor(i/2));} // given node in heap, returns index of parent

    int left(int i) {return 2*i;} // given node in heap, returns index of left child
    
    int right(int i) {return 2*i + 1;} // given node in heap, returns index of right child
	
	
	
    
    //void initializeMaxHeap(vector<T> a_list1); // init Max heap with data from vector
	//void initializeMinHeap(vector<T> a_list1); // init Min heap with data from vector
	
    //void swap(string *a, string *b);
    //T &getItem(int i) {return m_list[i];} // returns reference to i'th item
    
};




#endif //PROJECT3_HEAP_H
