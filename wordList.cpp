//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include "wordList.h"
#include <iostream>


// read in the list of words from the file
void wordList::readList(){
    std::ifstream read;
    std::string word;
    std::string name = "wordlist.txt";
    
    wlist.clear(); // clear the list
    
    read.open(name.c_str()); // open the file
    if (!read){
        // throw an error - include error.h file
    }
     
    // for each line in the file, push it into the list
    while (getline(read, word)){
        wlist.push_back(word);
    }

    read.close(); // close the file
}

// override of the print operator
std::ostream& operator<<(std::ostream& os, const wordList& list) {
    
    int count = 0;
    std::cout << "The list has the following words: " << std::endl;
    // for each word in the list, print it
    for (int i = 0; i < list.wlist.size(); i++) {
        os << list.wlist.at(i) << std::endl;
        count ++;
    }
    
    std::cout << "Total number of words in the list: " << count << std::endl;
    return os;
}

// getter for word list
std::vector<std::string> wordList::getList(){
    return wlist;
}

// use insertion sort to go through list
void wordList::InerstionSort(){
    
    int i, j;
    std::string key;
    
    for (j = 1; j < wlist.size(); j++){
        key = wlist.at(j); // the item to insert
        i = j - 1; // end of sorted portion
        
        while (i >= 0 && wlist.at(i) > key){
            // push item to the right, then add in key
            wlist.at(i +1) = wlist.at(i);
            i = i -1;
            wlist.at(i + 1) = key;
            i--;
        }
    }
    
}

// use merge sort to go through the list
void wordList::MergeSort(int p, int q){
    
    if (p < q){
        int m = floor((p+q)/2);
        MergeSort(p, m);
        MergeSort(m+1, q);
        Merge(p, m, q);
    }
}


void wordList::Merge(int p, int q, int r){

    int i, j, k;
    int n1 = q - p +1;
    int n2 = r-q;
    
    std::vector<std::string> L(n1), R(n2); // temporary vectors of length n1 and n2
    
   // copy temp vectors
    for (i = 0; i < n1; i++)
        L.at(i) = wlist.at(p+i);
    for (j = 0; j <n2; j++)
        R.at(j) = wlist.at(q + j +1);
    
    // merge temp vectors back to original, in order
    i = 0;
    j = 0;
    k = p;
    
    while (i < n1 && j <n2){
        // if the elemenet in the left vector is less than the one in the right
        if (L.at(i) <= R.at(j))
        {
            wlist.at(k) = L.at(i); // add it to new vector
            i++; // increment vector index
        }
        else // element in right vector is less
        {
            wlist.at(k) = L.at(j); // add it to new vector
            j++; // increment vector index
        }
        k++;
    }
    
    // if elements remain in L, copy them over to the sorted vector
    while(i<n1){
        wlist.at(k) = L.at(i);
        i++;
        k++;
    }
    
    // if elements remain in R, copy them over to the sorted vector
    while(i<n2){
        wlist.at(k) = L.at(j);
        j++;
        k++;
    }
}

// use quick sort to go through a list
void wordList::QuickSort(int s, int g){
    
    if (s < g){
        int p = Partition(s, g);
        QuickSort(s, p -1);
        QuickSort(p+1, g);
    }
}

// quick function to swap two elements
void swap(std::string *a, std::string *b)
{
    std::string s = *a;
    *a = *b;
    *b = s;
}


// partition for quick sort
int wordList::Partition(int p, int q){
    
    std::string len = wlist.at(q); // pivot point
    int i = (p - 1); // index of the smaller element
    
    for (int j = p; j <= q; j++){
        if (wlist.at(j) <= len){ // if the current element is smaller or equal to pivot
            i++;
            swap(&wlist.at(i), &wlist.at(j)); // swap the current element with index
        }
    }
    swap(&wlist.at(i+1), &wlist.at(q)); // swap pivot after all has been sorted
    return (i+1);
}


void wordList::HeapSort(){
    
}

bool wordList::lookUp(std::string word){
    
    int right, left, middle;
    left = 0;
    right = wlist.size() - 1;
    
    while(left <= right) // when the left side id less than or equal to right
    {
        middle = (left + right)/2; // find the middle point
        if (wlist.at(middle) == word) // if the word is the middle point
        {
            return true;
        }
        else if (wlist.at(middle) < word) // middle is than than the word - search right
        {
            left = middle + 1;
        }
        else // middle is greater than word - search left
        {
            right = middle -1;
        }
    }
    
    return false; // word is not in the list
}


