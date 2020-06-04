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
    
    grid(string a_filename); // constructor
    
    void readFile(string a_filename); // read in the file and store data
    int getRows() const; // gets the number of rows
    int getCols() const; // gets the number of columns
    
    string getChar(int a_row, int a_col) const; // get the characters a specific position
    
    matrix<string> m_grid; // matrix of characters
	
    void printGrid() const;
    
	friend ostream& operator << (ostream& cout, const grid& a_grid); // overload print function
 
};


#endif //PROJECT3_GRID_H
