/** 
 * @File:   main.cpp
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#include <fstream>

#include "Executive.h"

int main(int argc, char**argv) {
    std::string charFile = ".//charFile.txt";
    std::string intFile = ".//intFile.txt";
    std::string strFile = ".//strFile.txt";

    Executive overSeer = Executive(std::ifstream(charFile), std::ifstream(intFile), std::ifstream(strFile));

    overSeer.print();
    //overSeer.~Executive();
}