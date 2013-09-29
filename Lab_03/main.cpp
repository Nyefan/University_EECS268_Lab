/** 
 * @File:   main.cpp
 * @Author: Davis St. Aubin
 *
 * Created on September 16, 2013
 */

#include <fstream>

#include "Executive.h"

int main() {
    std::string charFile = ".//charFile.txt";
    std::string intFile = ".//intFile.txt";
    std::string strFile = ".//strFile.txt";

    std::ifstream charStream(charFile);
    std::ifstream intStream(intFile);
    std::ifstream strStream(strFile);

    Executive overSeer = Executive(charStream, intStream, strStream);
    
    overSeer.print();
    //overSeer.~Executive();
}
