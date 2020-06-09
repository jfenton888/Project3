//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_HEAP_H
#define PROJECT3_HEAP_H


//
//template class heap<T> that sorts a heap of type vector<T>, and which includes:
//
//(a) macros PARENT(int), LEFT(int), RIGHT(int)
//(b) for a max-heap, functions maxHeapify() and buildMaxHeap()
//(c) the equivalent functions for a min-heap
//(d) function heapSort()
//
// object is called with function heapSort, which modifies the vector passed to it
// 			but does not make a copy of it, avoiding duplicating large vectors
// maxHeap is the default heap style used, but can be overridden to minHeap by adding a second
// 			argument of bool false to call of heapSort function
// maxHeap will result in vector in ascending order (counting up or in alphabetical)
// minHeap will result in vector in descending order (counting down or in reverse alphabetical)
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
	
	void buildMaxHeap(vector<T>& a_list); // turns unsorted vector into max heap
	void maxHeapify(vector<T>& a_list, int a_heapSize, int i); // max heapifies node i (children = max heaps)
	
	void buildMinHeap(vector<T>& a_list); // turns unsorted vector into min heap
	void minHeapify(vector<T>& a_list, int a_heapSize, int i); // min heapifies node i (children = min heaps)
	
	void printHeap(vector<T>& a_heap);
	
public:
    
    heap()= default; //default constructor
	
	void heapSort(vector<T>& a_list, bool a_isMax=true); // creates max heap, sorts it (when given unsorted list)
	
};




#endif //PROJECT3_HEAP_H
