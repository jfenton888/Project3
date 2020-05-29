//
// Project by Jack Fenton
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-05-27.
//

#include "grid.h"
#include <fstream>
#include <vector>
#include <string>


// function to read in the file
void grid::readFile(std::string filename){
    
    // variables to be used to read file
    std::ifstream read;
    std::string line;
    std::string letter;
    int rows, cols;
    int r,c;
    
    read.open(filename.c_str()); // open the file
    
    if (!read){
           // throw an error - include error.h file
       }
     
    // get the number of rows and columns
    getline(read, line, ' ');
    rows = stoi(line);
    getline(read, line);
    cols = stoi(line);
    theGrid.resize(rows, cols); // size the grid based on readings
    
    for (r = 0; r < rows; r++){
        for (c = 0; r < cols -1; c++){
            // get the next letter, and place it in the grid
            getline(read, letter, ' ');
            theGrid[r][c] = letter;
        }        
    }
    
    read.close(); // close the file
}

// return the nummber of columns
int grid::getCols(){
    return theGrid.cols();
}

// return the number of rows
int grid::getRows(){
    return theGrid.rows();
}

// returns the character at a specific, given location
std::string grid::getChar(int r, int c){
    // check here about range of r and c
    
    return theGrid[r][c]
}

