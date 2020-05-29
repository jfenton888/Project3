//
// Project by Jack Fenton
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


template <typename T>
heap<T>::heap() // make empty heap
{
}

//initialize max heap from values in list1
template <typename T>
void heap<T>::initializeMaxHeap(std::vector<T> a_list1)
{
	for (int i = 0; i< a_list1.size(); i++)
		m_list.push_back(a_list1[i]);
	
	buildMaxHeap(int(m_list.size()));
}


template <typename T>
void heap<T>::maxHeapify(int i, int a_hsize)
{
	int l = left(i);
	int r = right(i);
	int large;
	
	// set large to the largest of the children and the root
	if (l <= a_hsize -1 && m_list.at(l) > m_list.at(i))
		large = l;
	else
		large = i;
	
	if (r <= a_hsize -1 && m_list.at(r) > m_list.at(large))
		large = r;
	
	// if the root isn't the largest, swap with largest child
	if (large != i)
	{
		swap(m_list[i], m_list[large]);
		maxHeapify(large, a_hsize);
	}
}


// turns unordered list into a max heap
template <typename T>
void heap<T>::buildMaxHeap(int a_hsize)
{
	// go through every element, starting at layer above leaves
	for (int i = int(floor(a_hsize /2)); i > 0; i--){
		maxHeapify(i, a_hsize);
	}
}





//initialize min heap from values in list1
template <typename T>
void heap<T>::initializeMinHeap(std::vector<T> a_list1)
{
	for (int i = 0; i< a_list1.size(); i++)
		m_list.push_back(a_list1[i]);
	
	buildMinHeap(int(m_list.size()));
}


template <typename T>
void heap<T>::minHeapify(int i, int a_hsize)
{
	int l = left(i);
	int r = right(i);
	int small;
	
	// set small to the smallest of the children and the root
	if (l <= a_hsize -1 && m_list.at(l) < m_list.at(i))
		small = l;
	else
		small = i;
	
	if (r <= a_hsize -1 && m_list.at(r) < m_list.at(small))
		small = r;
	
	// if the root isn't the smallest, swap with smallest child
	if (small != i)
	{
		swap(m_list[i], m_list[small]);
		minHeapify(small, a_hsize);
	}
}

// turns unordered list into a min heap
template <typename T>
void heap<T>::buildMinHeap(int a_hsize)
{
	// go through every element, starting at layer above leaves
	for (int i = int(floor(a_hsize /2)); i > 0; i--){
		minHeapify(i, a_hsize);
	}
}



// build max heap, and sort
template <typename T>
void heap<T>::heapSort(int a_hsize)
{
	buildMaxHeap(a_hsize);
	for (int i = a_hsize -1; i >= 0; i--){
		swap(m_list[0], m_list[i]);
		a_hsize --;
		
		maxHeapify(0, a_hsize);
	}
}



// quick function to swap two elements
template <typename T>
void heap<T>::swap(std::string *a, std::string *b)
{
	std::string s = *a;
	*a = *b;
	*b = s;
}






















