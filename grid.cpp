//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include "grid.h"
#include "matrix.h"
#include "matrix.cpp"
#include <fstream>
#include <vector>
#include <string>

using namespace std;


grid::grid(string a_filename)
{
	readFile(a_filename);
}



// return the number of columns
int grid::getCols() const
{
	return m_grid.cols();
}

// return the number of rows
int grid::getRows() const
{
	return m_grid.rows();
}

// returns the character at a specific, given location
string grid::getChar(int a_row, int a_col) const
{
	// check here about range of r and c
	return m_grid[a_row][a_col];
}




// function to read in the file
void grid::readFile(string a_filename)
{
    // variables to be used to read file
    string line;
    string letter;
    int rows, cols;
    int r,c;
    
    ifstream file(a_filename);
	
	if (file.is_open())
	{
		// get the number of rows and columns
		getline(file, line, ' ');
		rows = stoi(line);
		getline(file, line);
		cols = stoi(line);
		
		//cout<<"rows: "<<rows<<" cols: "<<cols<<endl;
		
		m_grid.resize(rows, cols); // size the grid based on readings
		
		for (r = 0; r < rows; r++)
		{
			for (c = 0; c < cols; c++)
			{
				// get the next letter, and place it in the grid
				getline(file, letter, ' ');
				m_grid[r][c] = letter;
			}
		}
	}
	else
		cout << "Unable to open file \n";
	
	file.close(); // close the file
	
}



void grid::printGrid() const
{
	for(int row=0;row<getRows();row++)
	{
		for(int col=0;col<getCols();col++)
		{
			cout<< getChar(row,col)<< " ";
		}
		cout<< endl;
	}
}


// override of the print operator
ostream& operator<<(ostream& cout, const grid& a_grid)
{
	a_grid.printGrid();
	return cout;
}


