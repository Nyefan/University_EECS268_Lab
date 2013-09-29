/** 
 * @File:   Executive.h
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#pragma once

#include <fstream>
#include <iostream>

#include "CountArray.h"


class Executive {
public:
    Executive(void);
    Executive(const Executive &orig);
    Executive(std::ifstream &charStream, std::ifstream &intStream, std::ifstream &strStream);
    virtual ~Executive(void);

private:
    bool toPrintChar = false;
    bool toPrintInt = false;
    bool toPrintStr = false;
  
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

