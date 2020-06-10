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
private:
	
	vector<string> m_allString;
	
public:
    
    grid(string a_filename); // constructor
	
	matrix<string> m_grid; // matrix of characters
    
    void readFile(string a_filename); // read in the file and store data
    
    int getRows() const {return m_grid.rows();}; // gets the number of rows
    int getCols() const {return m_grid.cols();}; // gets the number of columns
    
    string getChar(int a_row, int a_col) const; // get the characters a specific position
    
	//8 directions strings can be made going
	//each function adds the string from a starting coordinate
	//going in a certain direction for a specified length
    void addUp(int& a_row,int& a_col,int& a_len);
	void addUpRight(int& a_row,int& a_col,int& a_len);
	void addRight(int& a_row,int& a_col,int& a_len);
	void addDownRight(int& a_row,int& a_col,int& a_len);
	void addDown(int& a_row,int& a_col,int& a_len);
	void addDownLeft(int& a_row,int& a_col,int& a_len);
	void addLeft(int& a_row,int& a_col,int& a_len);
	void addUpLeft(int& a_row,int& a_col,int& a_len);
    
    
    vector<string> getStrings();
    
    void printGrid() const;
	friend ostream& operator << (ostream& cout, const grid& a_grid); // overload print function
 
};


#endif //PROJECT3_GRID_H
