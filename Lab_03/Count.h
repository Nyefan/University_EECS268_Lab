/** 
 * @File:   Count.h
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#pragma once
template <typename T>
class Count {
public:
    Count(void);
    Count(T t);
    Count(const Count &orig);
    virtual ~Count(void);

private:
    T item;
    int count;

public:
    void bumpCount();
    //bool equals(const T &t) const;
    T getItem() const;
    int getCount() const;
};

#include "Count.cpp"