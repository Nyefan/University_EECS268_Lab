#include "BoardSpace.h"


BoardSpace::BoardSpace(void) : numExits(0), beenUsed(false) {

}

BoardSpace::BoardSpace(int i) : numExits(0), beenUsed(false), space(i) {

}

void BoardSpace::addExit(BoardSpace *exitSpace) {
    exits[numExits] = exitSpace;
    ++numExits;
}

void BoardSpace::use() {
    beenUsed = true;
}

void BoardSpace::unuse() {
    beenUsed = false;
}

int BoardSpace::getNumExits() {
    return numExits;
}

int BoardSpace::getNumUnusedExits() {
    int temp = 0;
    for (int i = 0; i < numExits; i++) {
        if (!exits[i]->hasBeenUsed()) {
            ++temp;
        }
    }
    return temp;
}

int BoardSpace::getSpace() {
    return space;
}

bool BoardSpace::hasBeenUsed() {
    return beenUsed;
}

BoardSpace* BoardSpace::getExit(int numExit) {
    return exits[numExit];
}