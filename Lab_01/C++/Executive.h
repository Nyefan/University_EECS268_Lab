/** A file parser for pulling out Polynomials and directives from .txt files; 
 *  @file Executive.h
 *  @author Davis St. Aubin KUID 2482383
 */

#pragma once
#pragma once

#include <fstream>
#include <iostream>
#include <Polynomial.h>
#include <string>

class Executive {
public:
    const static int MAX_DEGREE = Polynomial::MAX_DEGREE;
    const static int MAX_POLYNOMIAL = 10;
private:
    Polynomial polynomials[MAX_POLYNOMIAL];
    void parsePolynomials(std::string fileName);
    void parseDirectives(std::string fileName);
    int getNextDouble(std::istream& inputStream, double& toStore);
    int getNextInt(std::istream& inputStream, int& toStore);
    void nextLine(std::istream& inputStream);
    bool throwsErrors(int checkVar, std::istream& inputFile, int polyNum);
public:
    /** Constructor for the executive class;
      * @param args  Contains strings that denote file locations for the Polynomial and Directive inputs;
      *     The first argument should contain the filename of the Polynomial input and the second should contain the directive filenames;
      * @pre None
      * @post An Executive is created and oversees the completion of the directives passed in args[1];
      */
    Executive(std::string args[2]);
};

