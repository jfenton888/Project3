//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#ifndef PROJECT3_GRID_H
#define PROJECT3_GRID_H

#include <fstream>
#include "matrix.h"
#include <string>

using namespace std;

//
//class called grid that reads the letters in the
//		grid from a file and stores them in a matrix
//

class grid
{
public:
    
    grid(){}; // constructor
    
    void readFile(string filename); // read in the file and store data
    int getRows(); // gets the number of rows
    int getCols(); // gets the number of columns
    
    string getChar(int a_row, int a_col); // get the characters a specific position
    
    matrix<string> theGrid; // matrix of characters

};


#endif //PROJECT3_GRID_H
