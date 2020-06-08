//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include <iostream>
#include "wordList.h"
#include "heap.h"
#include "heap.cpp"


using namespace std;

// read in the list of words from the file
void wordList::readList(string a_fileName)
{
    string word="NULL";
    m_wordList.clear(); // clear the list

    ifstream file(a_fileName); // open the file
    if (file.is_open())
    {
        while (getline(file, word)) // for each line in the file, push it into the list
            m_wordList.push_back(word);
    }
    else
        cout << "Unable to open file \n";
    
    file.close(); // close the file
}


// getter for word list
vector<string> wordList::getList()
{
    return m_wordList;
}

int wordList::getSize() const
{
    return m_wordList.size();
}

string wordList::getAt(int a_index) const
{
    return m_wordList.at(a_index);
}


// use insertion sort to go through list
void wordList::InerstionSort()
{
    int i, j;
    string key;
    
    for (j = 1; j < int(m_wordList.size()); j++)
    {
        key = m_wordList.at(j); // the item to insert
        i = j - 1; // end of sorted portion
        
        while (i >= 0 && m_wordList.at(i) > key)
        {
            // push item to the right, then add in key
            m_wordList.at(i +1) = m_wordList.at(i);
            i = i -1;
            m_wordList.at(i + 1) = key;
        }
    }
}

// use merge sort to go through the list
void wordList::MergeSort(int p, int q)
{
    if (p < q){
        int m = floor((p+q)/2);
        MergeSort(p, m);
        MergeSort(m+1, q);
        Merge(p, m, q);
    }
}


void wordList::Merge(int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p +1;
    int n2 = r-q;
    
    std::vector<std::string> L(n1), R(n2); // temporary vectors of length n1 and n2
    
   // copy temp vectors
    for (i = 0; i < n1; i++)
        L.at(i) = m_wordList.at(p+i);
    for (j = 0; j <n2; j++)
        R.at(j) = m_wordList.at(q + j +1);
    
    // merge temp vectors back to original, in order
    i = 0;
    j = 0;
    k = p;
    
    while (i < n1 && j <n2)
    {
        // if the elemenet in the left vector is less than the one in the right
        if (L.at(i) <= R.at(j))
        {
            m_wordList.at(k) = L.at(i); // add it to new vector
            i++; // increment vector index
        }
        else // element in right vector is less
        {
            m_wordList.at(k) = R.at(j); // add it to new vector
            j++; // increment vector index
        }
        k++;
    }
    
    // if elements remain in L, copy them over to the sorted vector
    while(i<n1)
    {
        m_wordList.at(k) = L.at(i);
        i++;
        k++;
    }
    
    // if elements remain in R, copy them over to the sorted vector
    while(i<n2)
    {
        m_wordList.at(k) = R.at(j);
        j++;
        k++;
    }
}

// use quick sort to go through a list
void wordList::QuickSort(int s, int g)
{
    
    if (s < g)
    {
        int p = Partition(s, g);
        QuickSort(s, p -1);
        QuickSort(p+1, g);
    }
}

// partition for quick sort
int wordList::Partition(int p, int q)
{

    std::string temp;
    std::string pivot = m_wordList.at(q); // pivot point
    int i = (p - 1); // index of the smaller element

    for (int j = p; j < q; j++)
    {
        if (m_wordList.at(j) <= pivot) // if the current element is smaller or equal to pivot
        {
            i++;
            // swap current element with index 
            temp = m_wordList.at(i);
            m_wordList.at(i) = m_wordList.at(j);
            m_wordList.at(j) = temp;
        }
    }

    // move pivot to middle 
    m_wordList.at(q) = m_wordList.at(i + 1);
        m_wordList.at(i + 1) = pivot;
        return (i + 1);
}


void wordList::HeapSort(string a_type)
{
    heap<string> thisHeap;
    thisHeap.heapSort(m_wordList, a_type);
    
}

bool wordList::lookUp(std::string a_word)
{
    
    int right, left, middle;
    left = 0;
    right = m_wordList.size() - 1;
    
    while(left <= right) // when the left side id less than or equal to right
    {
        middle = (left + right)/2; // find the middle point
        if (m_wordList.at(middle) == a_word) // if the word is the middle point
            return true;
        else if (m_wordList.at(middle) < a_word) // middle is than than the word - search right
            left = middle + 1;
        else // middle is greater than word - search left
            right = middle -1;
    }
    
    return false; // word is not in the list
}

int wordList::getrange() {
    int num = m_wordList.size() -1;
    return num;
}

// override of the print operator
ostream& operator<<(ostream& os, const wordList& a_list)
{
    
    int count = 0;
    
    cout << "The list has the following words: " << endl;
    // for each word in the list, print it
    for (int i = 0; i < a_list.getSize(); i++)
    {
        os << a_list.getAt(i) << std::endl;
        count ++;
    }
    
    cout << "Total number of words in the list: " << count << endl;
    return os;
}


