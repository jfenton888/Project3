//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "heap.h"

using namespace std;



#define PARENT(i) (floor(i/2)) // given node in heap, returns index of parent
#define LEFT(i) (2*i) // given node in heap, returns index of left child
#define RIGHT(i) (2*i + 1) // given node in heap, returns index of right child



// build max heap, and sort
template <typename T>
void heap<T>::heapSort(vector<T>& a_list, bool a_isMax)
{
	int heapSize=a_list.size();
	
	//Will create a max heap unless isMax is false
	if(a_isMax)
	{
		buildMaxHeap(a_list);
		for(int lastUnsorted=heapSize-1; lastUnsorted>=0; lastUnsorted--)
		{
			swap(a_list[0], a_list[lastUnsorted]);
			heapSize --;
			maxHeapify(a_list, heapSize, 0);
		}
	}
	else
	{
		buildMinHeap(a_list);
		for(int lastUnsorted=heapSize-1; lastUnsorted>=0; lastUnsorted--)
		{
			swap(a_list[0], a_list[lastUnsorted]);
			heapSize --;
			minHeapify(a_list, heapSize, 0);
		}
	}
	
}


// turns unordered list into a max heap
template <typename T>
void heap<T>::buildMaxHeap(vector<T>& a_list)
{
	int heapSize=a_list.size();
	// go through every element, starting at layer above leaves
	for (int i = int(floor(heapSize /2)); i >= 0; i--){
		maxHeapify(a_list, heapSize, i);
	}
}


template <typename T>
void heap<T>::maxHeapify(vector<T>& a_list, int a_heapSize, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int large;
	
	// set large to the largest of the children and the root
	if (l <= a_heapSize -1 && a_list[l] > a_list[i])
		large = l;
	else
		large = i;
	
	if (r <= a_heapSize -1 && a_list[r] > a_list[large])
		large = r;
	
	// if the root isn't the largest, swap with largest child
	if (large != i)
	{
		swap(a_list.at(i), a_list.at(large));
		maxHeapify(a_list, a_heapSize, large);
	}
}




// turns unordered list into a min heap
template <typename T>
void heap<T>::buildMinHeap(vector<T>& a_list)
{
	int heapSize=a_list.size();
	// go through every element, starting at layer above leaves
	for (int i = int(floor(heapSize /2)); i >= 0; i--)
	{
		minHeapify(a_list, heapSize, i);
	}
}



template <typename T>
void heap<T>::minHeapify(vector<T>& a_list, int a_heapSize, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int small;
	
	// set small to the smallest of the children and the root
	if (l <= a_heapSize -1 && a_list[l] < a_list[i])
		small = l;
	else
		small = i;
	
	if (r <= a_heapSize -1 && a_list[r] < a_list[small])
		small = r;
	
	// if the root isn't the smallest, swap with smallest child
	if (small != i)
	{
		swap(a_list[i], a_list[small]);
		minHeapify(a_list, a_heapSize, small);
	}
}


template <typename  T>
void heap<T>::printHeap(vector<T>& a_heap)
{
	for(auto current:a_heap)
		cout<<current<<" ";
	cout<<endl;
}



