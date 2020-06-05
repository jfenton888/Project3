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
	while(a_row<0)
		a_row=getRows()+a_row;
	while(a_row>=getRows())
		a_row-=getRows();
	while(a_col<0)
		a_col=getCols()+a_col;
	while(a_col>=getCols())
		a_col-=getCols();
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

void grid::addUp(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row+it,a_col));
	cout<<"UP a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addUpRight(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row+it,a_col+it));
	cout<<"UPRIGHT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addRight(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row,a_col+it));
	cout<<"RIGHT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addDownRight(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row-it,a_col+it));
	cout<<"DOWNRIGHT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addDown(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row-it,a_col));
	cout<<"DOWN a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addDownLeft(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row-it,a_col-it));
	cout<<"DOWNLEFT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addLeft(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row,a_col-it));
	cout<<"LEFT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}

void grid::addUpLeft(int& a_row,int& a_col,int& a_len)
{
	string thisString;
	for(int it=0;it<a_len;it++)
		thisString.append(getChar(a_row+it,a_col-it));
	cout<<"UPLEFT a_len: "<<a_len<<" "<<thisString<<endl;
	m_allString.push_back(thisString);
}





vector<string> grid::getStrings()
{
	for(int row=0; row<getRows();row++)
	{
		for(int col=0;col<getCols();col++)
		{
			for(int len=5;len<=6;len++)
			{
				addUp(row,col,len);
				addUpRight(row,col,len);
				addRight(row,col,len);
				addDownRight(row,col,len);
				addDown(row,col,len);
				addDownLeft(row,col,len);
				addLeft(row,col,len);
				addUpLeft(row,col,len);
			}
		}
	}
	return m_allString;
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


