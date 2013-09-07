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
    Executive(std::string args[2]);
};

