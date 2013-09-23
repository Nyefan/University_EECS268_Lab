/** 
 * @File:   CountArray.cpp
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

//#include "CountArray.h"

template <typename T>
CountArray<T>::CountArray(void) {
    container = new Count<T>[10];
    arraySize = 10;
    numItemsStored = 0;
}

template <typename T>
CountArray<T>::CountArray(const CountArray &orig) {
    arraySize = orig.arraySize;
    numItemsStored = orig.numItemsStored;
    container = new Count<T>[arraySize];
    for (int i = 0; i < arraySize; i++) {
        container[i] = orig.container[i];
    }
}

template <typename T>
CountArray<T>::~CountArray(void) {
    delete container;
}

template <typename T>
void CountArray<T>::bumpCount(T t) {
    // Bump the count of t an equivalent object is already in container;
    if (contains(T, indexOfT)) {
        container[indexOfT].bumpCount();
    }

    else {
        // Increase the size of container if necessary;
        if (numItemsStored >= arraySize) {
            int tempSize = 2*arraySize;
            Count<T> *temp = new Count<T>[tempSize];
            for (int i = 0; i < arraySize) {
                temp[i] = container[i];
            }
            delete container;
            container = temp;
            arraySize *= 2;
        }

        // Place the new object in the first free slot;
        container[numItemsStored] = Count<T>(t);
        ++numItemsStored;
    }
}

template <typename T>
Count<T> CountArray<T>::getItem(int index) const {
    return container[index];
}

template <typename T>
int CountArray<T>::getNumItemsStored() const {
    return numItemsStored;
}

/* Beginning private methods */

template <typename T>
bool CountArray<T>::contains(T t, int &index) const {
    for (int i = 0; i < numItemsStored; i++) {
        if (container[i] == t) {
            index = i;
            return true;
        }
    }
    index = 0; 
    return false;
}









