/** 
 * @File:   CountArray.h
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#pragma once

#include "Count.h"

template <typename T>
class CountArray {
public:
    CountArray(void);
    CountArray(const CountArray &orig);
    virtual ~CountArray(void);

private:
    Count<T> *container;
    int arraySize;
    int numItemsStored;
    bool contains(T t, int &index) const;

public:
    void bumpCount(T t);
    Count<T> getItem(int index) const;
    int getNumItemsStored() const;
    //void print() const;
};

#include "CountArray.cpp"

