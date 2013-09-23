/** 
 * @File:   Executive.cpp
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#include "Executive.h"


Executive::Executive(void) {

}

Executive::Executive(const Executive &orig) {
    charArray = CountArray<char>(orig.charArray);
    intArray = CountArray<int>(orig.intArray);
    strArray = CountArray<std::string>(orig.strArray);
}

Executive::Executive(std::istream &charStream, std::istream &intStream, std::istream &strStream) {
    this->charArray = CountArray<char>();
    this->intArray = CountArray<int>();
    this->strArray = CountArray<std::string>();

    read(charStream, charArray);
    read(intStream, intArray);
    read(strStream, strArray);
}

Executive::~Executive(void) {
    charArray.~CountArray();
    intArray.~CountArray();
    strArray.~CountArray();
}

/* Public methods */

void Executive::print() {
    print(this->charArray);
    print(this->intArray);
    print(this->strArray);
}

/* Private methods */

/* Private static methods */

template <typename T>
static void print(const CountArray<T> arr) {

}

template <typename T>
static void read(std::istream &is, CountArray<T> &arr) {

}
