//
//  matrix.h
//  p3
//
//  Created by Tamara Kahhale on 5/28/20.
//  Copyright © 2020 Tamara Kahhale. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <vector>

template <typename T>

class matrix {

public:s
    matrix(int numRows = 1, int numCols = 1,const T& initVal = T());
    vector<T>& operator[] (int i);
    const vector<T>& operator[](int i) const;
    int rows() const;
    int cols() const;
    void resize(int numRows, int numCols);

private:
    int nRows, nCols;
    vector<vector<T> > mat; };

#endif /* matrix_h */

