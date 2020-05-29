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

template <typename T>

class heap
{
private:

    std::vector<T> list;

public:
    
    heap(); //constructor
    
    void initializeMaxHeap(std::vector<T> list1); // init Max heap with data from vector
    void maxHeapify(int i, int hsize); // max heapifies node i (children = max heaps)
    void buildMaxHeap(int hsize); // turns unsorted vector into max heap
    
    void initializeMinHeap(std::vector<T> list1); // init Min heap with data from vector
    void minHeapify(int i, int hsize); // min heapifies node i (children = min heaps)
    void buildMinHeap(int hsize); // turns undsorted vector into min heap
    
    void heapSort(int hsize); // creates max heap, sorts it (when given unsorted list)
        
    
    int parent(int i) {return floor(i/2);} // given node in heap, returns index of parent

    int left(int i) {return 2*i;} // given node in heap, returns index of left child
    
    int right(int i) {return 2*i + 1;} // given node in heap, returns index of right child
    
    
    T &getItem(int i) {return list[i];} // returns reference to i'th item
    void swap(std::string *a, std::string *b);
    
    
};

// quick function to swap two elements
template <typename T>
void heap<T>::swap(std::string *a, std::string *b)
{
    std::string s = *a;
    *a = *b;
    *b = s;
}

template <typename T>
heap<T>::heap() // make empty heap
{
}

//initialize max heap from values in list1
template <typename T>
void heap<T>::initializeMaxHeap(std::vector<T> list1)
{
    for (int i = 0; i< list1.size(); i++)
        list.push_back(list1[i]);
    
    buildMaxHeap(list.size());
}

template <typename T>
void heap<T>::maxHeapify(int i, int hsize)
{
    int l = left(i);
    int r = right(i);
    int large;
    
    // set large to the largest of the children and the root
    if (l <= hsize -1 && list.at(l) > list.at(i))
        large = l;
    else
        large = i;
    
    if (r <= hsize -1 && list.at(r) > list.at(large))
        large = r;
    
    // if the root isn't the largest, swap with largest child
    if (large != i)
    {
        swap(list[i], list[large]);
        maxHeapify(large, hsize);
    }
}

// turns unordered list into a max heap
template <typename T>
void heap<T>::buildMaxHeap(int hsize)
{
    // go through every element, starting at layer above leaves
    for (int i = floor(hsize /2); i > 0; i--){
        maxHeapify(i, hsize);
    }
}



//initialize min heap from values in list1
template <typename T>
void heap<T>::initializeMinHeap(std::vector<T> list1)
{
    for (int i = 0; i< list1.size(); i++)
        list.push_back(list1[i]);
    
    buildMinHeap(list.size());
}


template <typename T>
void heap<T>::minHeapify(int i, int hsize)
{
    int l = left(i);
    int r = right(i);
    int small;
    
    // set small to the smallest of the children and the root
    if (l <= hsize -1 && list.at(l) < list.at(i))
        small = l;
    else
        small = i;
    
    if (r <= hsize -1 && list.at(r) < list.at(small))
        small = r;
    
    // if the root isn't the smallest, swap with smallest child
    if (small != i)
    {
        swap(list[i], list[small]);
        minHeapify(small, hsize);
    }
}

// turns unordered list into a min heap
template <typename T>
void heap<T>::buildMinHeap(int hsize)
{
    // go through every element, starting at layer above leaves
    for (int i = floor(hsize /2); i > 0; i--){
        minHeapify(i, hsize);
    }
}

// build max heap, and sort
template <typename T>
void heap<T>::heapsort(int hsize)
{
    buildMaxHeap(hsize);
    for (int i = hsize.size() -1; i >= 0; i--){
        swap(list[0], list[i]);
        hsize --;
        
        maxHeapify(0, hsize);
    }
}


#endif //PROJECT3_HEAP_H
