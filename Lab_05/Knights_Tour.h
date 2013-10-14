#pragma once

#include <vector>

#include "BoardSpace.h"

class Knights_Tour
{
public: // Constructors and Destructor;
    /** A default constructor
    * @pre None
    * @post This object has been created (but not initialized; use the other constructor for that)
    */
    Knights_Tour(void);
    /** A constructor that builds the board and sets the initial position of the knight;
    * @param numRows  The number of rows on the chessboard to consider
    * @param numCols  The number of columns on the chessboard to consider
    * @param initRow  The initial row posion of the knight
    * @param initCol  The initial column position of the knight
    * @pre None
    * @post This object has been created and initialized;
    */
    Knights_Tour(int numRows, int numCols, int initRow, int initCol);
    
    /** A destructor
    * @pre None
    * @post None
    */
    ~Knights_Tour(void);

private: // Internal functions and data objects;
    BoardSpace** board;
    std::vector<int> path;
    bool validPathFound;
    int numRows;
    int numCols;
    int numel;
    int initRow;
    int initCol;

    void link(int i, int j);
    void populateBoard();


public: // External functionality;
    /** Attempts to find a complete "knight's tour" with the given board size and initial position
    * @pre This object has been initialized
    * @post Either a path has been populated (returns true), or it has been determined that no viable path exists for the given set of inputs (returns false
    * @return true if a valid path has been found; false if no valid path exists
    */
    bool findPath();
    /** Prints the knight's tour to the terminal; if a valid knight's tour has been found, that path will be printed to the terminal; else an empty board will be printed;
    * @pre None
    * @post None
    */
    void print();
};

