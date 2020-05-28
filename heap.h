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
//				which returns the nth item in the heap.
//(b) for a max-heap, functions initialize MaxHeap(), maxHeapify(), and buildMaxHeap().
//(c) the equivalent functions for a min-heap. You can implement the
//			max-heap and min-heap data structures within the same
//			class and convert the stored data into a min- or max-heap
//			by calling the appropriate member functions.
//(d) function heapSort()
//


class heap
{
private:



public:
	
	int parent();

	int left();
	
	int right();
	
	int getItem();
	
	void initializeMaxHeap();
	
	void maxHeapify();
	
	void buildMaxHeap();
	
	void heapSort();
	
	
};


#endif //PROJECT3_HEAP_H
