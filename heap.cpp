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
heap<T>::heap()
{
}



// build max heap, and sort
template <typename T>
void heap<T>::heapSort(vector<T>& a_list, string a_type)
{
	int heapSize=a_list.size();
	
	if(a_type=="max")
	{
		buildMaxHeap(a_list);
		for (int i = heapSize -1; i >= 0; i--)
		{
			swap(a_list[0], a_list[i]);
			heapSize --;
			maxHeapify(a_list, heapSize, 0);
		}
	}
	else if(a_type=="min")
	{
		buildMinHeap(a_list);
		for (int i = heapSize -1; i >= 0; i--)
		{
			swap(a_list[0], a_list[i]);
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
	for (int i = int(floor(heapSize /2)); i > 0; i--){
		maxHeapify(a_list, heapSize, i);
	}
}


template <typename T>
void heap<T>::maxHeapify(vector<T>& a_list, int a_heapSize, int i)
{
	int l = left(i);
	int r = right(i);
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
	for (int i = int(floor(heapSize /2)); i > 0; i--){
		minHeapify(a_list, heapSize, i);
	}
}



template <typename T>
void heap<T>::minHeapify(vector<T>& a_list, int a_heapSize, int i)
{
	int l = left(i);
	int r = right(i);
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








/*
//quick function to swap two elements
template <typename T>
void heap<T>::swap(string *a, string *b)
{
	string s = *a;
	*a = *b;
	*b = s;
}


//initialize max heap from values in list1
template <typename T>
void heap<T>::initializeMaxHeap(std::vector<T> a_list1)
{
	for (int i = 0; i< a_list1.size(); i++)
		m_list.push_back(a_list1[i]);
	
	buildMaxHeap(int(m_list.size()));
}


//initialize min heap from values in list1
template <typename T>
void heap<T>::initializeMinHeap(std::vector<T> a_list1)
{
	for (int i = 0; i< a_list1.size(); i++)
		m_list.push_back(a_list1[i]);
	
	buildMinHeap(int(m_list.size()));
}
*/
















