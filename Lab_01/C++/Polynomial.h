/** A container for polynomial data; 
 *  @file Polynomial.h
 *  @author Davis St. Aubin KUID 2482383
 */

#pragma once

#include <iomanip>
#include <iostream>
#include <string>

class Polynomial {
public:
    const static int MAX_DEGREE = 21;
private:
    double coefficients[MAX_DEGREE];
    int length;
    int PRINT_PRECISION;
    std::string printable;
    double sum;
public:
    /** A default constructor that initializes the Polynomial to be 0;
      * @pre None;
      * @post A Polynomial object is created where all coefficients are 0;
      */
    Polynomial();
    /** A constructor that initializes the Polynomial according to the input;
      * @param coefficients  An array of coefficients formatted to match the form, "c0 + c1x^1 + c2x^2 + ...";
      * @param order  The highest order of x in the polynomial. Note that this should be 1 less than the length of coefficients;
      * @pre None;
      * @post A Polynomial object is created according to the input;
      */
    Polynomial(double coefficients[], int order);
    /** Adds two Polynomials together and returns a new Polynomial containing the sum;
      * @param p2  The Polynomial to be added to this one;
      * @param toPrint  If true, the result is printed to std::cout;  Defaults to false if no input is given;
      * @pre Both Polynomials should be initialized;
      * @post No change is made to either Polynomial; Instead, a new Polynomial is created to contain the output;
      * @return A new Polynomial that is the sum of this and p2;
      */
    Polynomial add(Polynomial p2, const bool toPrint);
    /** Differentiates the Polynomial and returns a new Polynomial containing the result;
      * @param toPrint  If true, the result is printed to std::cout;  Defaults to false if no input is given;
      * @pre This Polynomial should be initialized;
      * @post No change is made to this Polynomial; Instead, a new Polynomial is created to contain the output;
      * @return A new Polynomial that is the derivative of this;
      */
    Polynomial differentiate(const bool toPrint);
    /** Finds the value of this Polynomial at x;
      * @param x  The value for which this Polynomial should be evaluated;
      * @param toPrint  If true, the result is printed to std::cout;  Defaluts to false if no input is given;
      * @pre This Polynomial should be initialized;
      * @post No change is made to this Polynomial; A new double is created to contain the output;
      * @return A double containing the value of this Polynomial evaluated at x
      */
    double evaluate(const double x, const bool toPrint);
    /** Prints a neatly formatted version of this Polynomial to std::cout;
      * @pre Thie Polynomial should be initialized;
      * @post No change is made to this Polynomial; 
      */
    void print();
};

