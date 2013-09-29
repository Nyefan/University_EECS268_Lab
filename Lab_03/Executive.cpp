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

Executive::Executive(std::ifstream &charStream, std::ifstream &intStream, std::ifstream &strStream) {
    charArray = CountArray<char>();
    intArray = CountArray<int>();
    strArray = CountArray<std::string>();
    
    if (charStream.is_open()) {
        toPrintChar = true;
        read(charStream, charArray);
    } else {std::cout << "Unable to open character file.";}
    
    if (intStream.is_open()) {
        toPrintInt = true;
        read(intStream, intArray);
    } else {std::cout << "Unable to open integer file.";}
    
    if (strStream.is_open()) {
        toPrintStr = true;
        read(strStream, strArray);
    } else {std::cout << "Unable to open string file.";}
    
    
}

Executive::~Executive(void) {
    charArray.~CountArray();
    intArray.~CountArray();
    strArray.~CountArray();
}

/* Public methods */

void Executive::print() {
  if (toPrintChar) {
    std::cout << "Character Array:";
    print(this->charArray);
  }
  if (toPrintInt) {
    std::cout << "Integer Array:";
    print(this->intArray);
  }
  if (toPrintStr) {
    std::cout << "String Array:";
    print(this->strArray);
  }
}

/* Private methods */

/* Private static methods */

template <typename T>
void Executive::print(const CountArray<T> arr) {
    for(int i = 0; i < arr.getNumItemsStored(); i++) {
      std::cout << arr.getItem(i).getItem() << ", " << arr.getItem(i).getCount();
    }
}

template <typename T>
void Executive::read(std::istream &is, CountArray<T> &arr) {
    T temp;
    int counter = 0;
    while(!is.eof()) {
      if (counter == 5) {
        print(arr);
        counter = 0;
      }
      is >> temp;
      arr.bumpCount(temp);
      ++counter;
    }
}
