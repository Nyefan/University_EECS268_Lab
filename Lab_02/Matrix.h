/**
 * @file:   Matrix.h
 * @author: Davis St. Aubin
 *
 * Created on September 9, 2013, 3:05 PM
 */

#pragma once

#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#define additionSizeError "Cannot add matrices with two different sizes"
#define multiplySizeError "Cannot multiply these two matrices together in this order"
#define fParsingSizeError "The input matrix size is too large"

class Matrix {
public:
  const static int MAX_NUMROW = 100;
  const static int MAX_NUMCOL = 100;
private:
  int numRows;
  int numCols;
  double mat[MAX_NUMROW][MAX_NUMCOL];
public:
  /** A default constructor that initializes the Matrix to be 0 size;
    * @pre None;
    * @post A Matrix object of size 0;
    */
  Matrix();
  /** A constructor that initializes an empty Matrix of size numRows x numCols;
    * @param numRows  The number of rows in the matrix;
    * @param numCols  The number of columns in the matrix;
    * @pre None;
    * @post An empty Matrix object of size numRows x numCols;
    */
  Matrix(int numRows, int numCols);
  /** A constructor that initializes a filled Matrix of size numRows x numCols;
    * @param numRows  The number of rows in the matrix;
    * @param numCols  The number of columns in the matrix;
    * @param inputArray  The data to be contained by the Matrix;
    * @pre None;
    * @post A Matrix object filled with data from inputArray;
    */
  Matrix(int numRows, int numCols, double inputArray[100][100]);
  /** A copy constructor;
    * @param b  The matrix to be copied;
    * @pre Matrix b should be initialized;
    * @post A Matrix object that is a literal copy of b;
    */
  Matrix(const Matrix &b);
  /** Adds m2 to this Matrix and returns a new matrix containing the result;
    * @param m2  The Matrix to be added to this one;
    * @param toPrint  If true, prints the input and resulting matrices to the std::cout;
    * @pre  This Matrix and m2 should be of the same size;
    * @post  A new Matrix object that contains the sum of this and m2;
    */
  Matrix matrixAdd(const Matrix &m2, const bool &toPrint) const;
  /** Adds c to every element of this Matrix and returns a new matrix containing the result;
    * @param c  The value to add to this Matrix;
    * @param toPrint  If true, prints the input and resulting matrices to the std::cout;
    * @pre This Matrix should be initialized with values;
    * @post A new Matrix object that contains the sum of this and c;
    */
  Matrix elementAdd(const double &c, const bool &toPrint) const;
  /** Multiplies this Matrix and m2 and returns a new Matrix containing the results;
    * @param m2  The Matrix to multiply with this one;
    * @param inFront  If true, evaluates as this*m2; else evaluates as m2*this;
    * @param toPrint  If true, prints the input and resulting matrices to the std::cout;
    * @pre This Matrix and m2 should be initialized with sizes that go as mxn * nxm;
    * @post A new Matrix object that contains the product of this and m2;
    */
  Matrix matrixMultiply(const Matrix &m2, const bool inFront, const bool &toPrint) const;//check size on multiply;
  /** Multiplies every element in this matrix by c and returns a new Matrix containing the results;
    * @param c  The value to multiply with this Matrix;
    * @param toPrint  If true, prints the input a resulting matrices to the std::cout;
    * @pre This Matrix should be initialized with values;
    * @post A new Matrix object that contains the product of this and c;
    */
  Matrix elementMultiply(const double &c, const bool &toPrint) const;
  /** Transposes this Matrix and returns a new Matrix containing the result;
    * @param toPrint  If true, prints the input and resulting matrices to the std::cout;
    * @pre This Matrix should be initialized with values;
    * @post A new Matrix object that contains the transpose of this;
    */
  Matrix transpose(const bool &toPrint = 0) const;
  /** Prints this Matrix to the std::cout;
    * @pre This Matrix should be initialized with values;
    * @post None;
    */
  void print() const;
  /** Prints this Matrix to the std::ostream os;
    * @pre This Matrix should be initialized with values;
    * @post None:
    */
  void print(std::ostream &os) const;
};

