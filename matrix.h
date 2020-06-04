//
//  matrix.h
//  p3
//
//  Created by Tamara Kahhale on 5/28/20.
//  Copyright © 2020 Tamara Kahhale. All rights reserved.
//

#ifndef PROJECT3_MATRIX_H
#define PROJECT3_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class matrix {
private:
    int m_nRows;
    int m_nCols; // number of rows and columns
    vector<vector<T>> mat; // matrix implemented as vector with nRows and nColumns
    
    
public:
    matrix(int a_nRows = 1, int a_nCols = 1,const T& a_initVal = T()); // constructor
    
    vector<T>& operator[] (int a_index); // index operator
    matrix<T> &operator=(matrix<T> a_mat);
    
    const vector<T>& operator[](int a_index) const;
    
    int rows() const; // returns number of rows
    int cols() const; // returns number of columns
    
    void resize(int a_nRows, int a_nCols); // changes the size of the matrix


};



#endif //PROJECT3_MATRIX_H

