#pragma once

#include <iostream>
#include <string>

class Polynomial {
public:
    const static int MAX_DEGREE = 20;
private:
    double coefficients[MAX_DEGREE];
    int order;
    std::string printable;
    double sum;
    void parseCoefficients();
public:
    Polynomial();
    Polynomial(double coefficients[], int order);
    Polynomial add(Polynomial p2, const bool toPrint);
    Polynomial differentiate(const bool toPrint);
    double evaluate(const double x, const bool toPrint);
    void print();
};

