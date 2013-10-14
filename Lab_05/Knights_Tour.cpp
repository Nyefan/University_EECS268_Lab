#include <iomanip>
#include <iostream>

#include "Knights_Tour.h"


Knights_Tour::Knights_Tour(void) {
    board = nullptr;
}

Knights_Tour::Knights_Tour(int numRows, int numCols, int initRow, int initCol) :
                           numRows(numRows), numCols(numCols),
                           initRow(initRow), initCol(initCol),
                           validPathFound(false) {
    numel = numRows*numCols;
    board = new BoardSpace*[numRows*numCols];
    populateBoard();
    // Push the initial space to path;
    BoardSpace *initSpace = board[initRow*numCols + initCol];
    path.push_back(initSpace->getSpace());
    initSpace->use();
}

Knights_Tour::~Knights_Tour(void) {
    if (board!=nullptr) { // Call the destructor on each element of board, then delete board;
        
        //TODO: delete each pointer in board BEFORE deleting board;

        delete [] board;
    }
}

bool Knights_Tour::findPath() {
    
    //Debugging:
    //std::cout << "\npath is " << path.front();
    //for (int i = 1; i < path.size(); i++) {
    //    std::cout << ", " << path.at(i);
    //} std::cout << '\n';
    //print();
    //end Debugging;

    BoardSpace *temp = board[path.back()]; // Don't delete this because it's part of board;

    // Check base conditions;
    if (path.size() == numel) {
        return true;
    } else if (temp->getNumUnusedExits() == 0) {
        board[path.back()]->unuse();
        path.pop_back();
        return false;
    } else {

        for (int i = 0; i < temp->getNumExits(); i++) {
            // Try to find a valid path from each exitSpace of currentSpace;
            BoardSpace *tempExit = temp->getExit(i); // Don't delete this because it's part of board;
            if (!tempExit->hasBeenUsed()) {
                path.push_back(tempExit->getSpace());
                tempExit->use();
                if (findPath()) {
                    validPathFound = true;
                }
            }
        }

        // Refresh the path if no valid path can be found from this point forward;
        if (!validPathFound) {
            board[path.back()]->unuse();
            path.pop_back();
        }
        return validPathFound;
    }
        

}

void Knights_Tour::print() {
    //Initialize the printable array to contain all zeroes;
    int *order = new int[numel];
    for (int i = 0; i < numel; i++) {
        order[i] = 0;
    }

    //Print the path to the terminal if a valid path was found;
    // else, print an empty board with the initial space filled;
    if (validPathFound) {
        for (int i = 0; i < path.size(); i++) {
            order[path.at(i)] = i;
        }

        for (int i = 0; i < numel; i++) {
            if (i%numCols == 0) {std::cout << '\n';}
            std::cout << '[' << std::setw(2) << order[i] << ']';
        } std::cout << "\n\n";
    } else {
        int initLoc = initRow*numCols + initCol;
        for (int i = 0; i < numel; i++) {
            if (i%numCols == 0) {std::cout << '\n';}
            
            if (i == initLoc) {
                std::cout << "[ 0]";
                continue;
            }

            std::cout << "[  ]";
        }
    }

    // delete the printable array allocated at the top of this function;
    // TODO: make order a private class variable;
    delete [] order;
}

void Knights_Tour::populateBoard() {
    //Initialize every space on the board;
    for (int i = 0; i < numel; i++) {
        board[i] = new BoardSpace(i);
    }

    //Test each move the knight can make and link the current space to valid exit spaces;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int currentSpace = row*numCols+col;
            if (row - 2 >= 0) {
                if (col - 1 >= 0) {
                    link(currentSpace, (row-2)*numCols+col-1);
                }
                if (col + 1 < numCols) {
                    link(currentSpace, (row-2)*numCols+col+1);
                }
            }
            if (row - 1 >= 0) {
                if (col - 2 >= 0) {
                    link(currentSpace, (row-1)*numCols+col-2);
                }
                if (col + 2 < numCols) {
                    link(currentSpace, (row-1)*numCols+col+2);
                }
            }
            if (row + 1 < numRows) {
                if (col - 2 >= 0) {
                    link(currentSpace, (row+1)*numCols+col-2);
                }
                if (col + 2 < numCols) {
                    link(currentSpace, (row+1)*numCols+col+2);
                }
            }
            if (row + 2 < numRows) {
                if (col - 1 >= 0) {
                    link(currentSpace, (row+2)*numCols+col-1);
                }
                if (col + 1 < numCols) {
                    link(currentSpace, (row+2)*numCols+col+1);
                }
            }
        }
    }

    //Debugging
    //for (int i = 0; i < numel; i++) {
    //    std::cout << board[i]->getSpace();
    //    std::cout << ", " << board[i]->hasBeenUsed();
    //    std::cout << ", " << board[i]->getNumExits() << ": ";
    //    for (int j = 0; j < board[i]->getNumExits(); j++) {
    //        std::cout << board[i]->getExit(j)->getSpace() << ", ";
    //    } std::cout << '\n';
    //    //std::cout << ", " << board[i]->getNumUnusedExits() << '\n';
    //}
    //end Debugging;
}

void Knights_Tour::link(int i, int j) {
    //Link spaces together that can move to each other;
    if (i >= 0 && j >= 0) {
        board[i]->addExit(board[j]);
    }
}