/** 
 * @File:   Executive.h
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#pragma once

#include <fstream>

#include "CountArray.h"


class Executive {
public:
    Executive(void);
    Executive(const Executive &orig);
    Executive(std::istream &charStream, std::istream &intStream, std::istream &strStream);
    virtual ~Executive(void);

private:
    CountArray<char> charArray;
    CountArray<int> intArray;
    CountArray<std::string> strArray;

    template <typename T>
    static void print(const CountArray<T> arr); // arr MUST be passed by value;

    template <typename T>
    static void read(std::istream &is, CountArray<T> &arr);

public:
    void print();
};

