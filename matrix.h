//
//  matrix.h
//  p3
//
//  Created by Tamara Kahhale on 5/28/20.
//  Copyright © 2020 Tamara Kahhale. All rights reserved.
//

#ifndef PROJECT3_MATRIX_H
#define PROJECT3_MATRIX_H

#include <vector>

template <typename T>

class matrix {
private:
    int m_nRows;
    int m_nCols; // number of rows and columns
    std::vector<std::vector<T> > mat; // matrix implemented as vector with nrows and ncolumns
    
    
public:
    matrix(int numRows = 1, int numCols = 1,const T& initVal = T()); // constructor
    
    std::vector<T>& operator[] (int i); // index operator
    matrix<T> &operator=(matrix<T> m);
    
    const std::vector<T>& operator[](int i) const;
    
    int rows() const; // returns number of rows
    int cols() const; // returns number of columns
    
    void resize(int numRows, int numCols); // changes the size of the matrix


};




template <typename T>
matrix<T>::matrix(int numRows, int numCols, const T& initVal):
m_nRows(numRows), m_nCols(numCols), mat(numRows, std::vector<T>(numCols, initVal))
{}

// non-constant version: provides general access to matrix elements
template <typename T>
std::vector<T>& matrix<T>::operator[] (int i)
{
   if (i < 0 || i >= m_nRows)
       // throw range error - include error file
   return mat[i];
}

// constant version, does not allow modification of a matrix element
template <typename T>
const std::vector<T>& matrix<T>::operator[] (int i) const
{
   if (i < 0 || i >= m_nRows)
      // throw range error
   return mat[i];
}


template <typename T>
matrix<T> &matrix<T>::operator=(matrix<T> m)
{
   for (int i = 0; i < rows(); i++)
      for (int j = 0; j < cols(); j++)
         (*this)[i][j] = m[i][j];
   
   return *this;
}

template <typename T>
int matrix<T>::rows() const
{
   return m_nRows;
}

template <typename T>
int matrix<T>::cols() const
{
   return m_nCols;
}

template <typename T>
void matrix<T>::resize(int numRows, int numCols)
{
   int i;
   
   // no size
   if (numRows == m_nRows && numCols == m_nCols)
      return;

   // new matrix size
   m_nRows = numRows;
   m_nCols = numCols;

   // resize rows
   mat.resize(m_nRows);

   // resize each row with columns
   for (i=0; i < m_nRows; i++)
      mat[i].resize(m_nCols);
}


#endif //PROJECT3_MATRIX_H

