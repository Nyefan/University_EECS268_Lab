/** 
 * @file:   Matrix.cpp
 * @author: Davis St. Aubin
 * 
 * Created on September 9, 2013, 3:05 PM
 */

#include "Matrix.h"

Matrix::Matrix() : numRows(MAX_NUMROW), numCols(MAX_NUMCOL) {
}

Matrix::Matrix(int numRows, int numCols) {
  this->numRows = numRows;
  this->numCols = numCols;
}

Matrix::Matrix(int numRows, int numCols, double inputArray[100][100]) { //size mismatch;
  this->numRows = numRows;
  this->numCols = numCols;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      this->mat[i][j] = inputArray[i][j];
    }
  }
}

Matrix::Matrix(const Matrix &b) {
//  std::memcpy(this, b, sizeof(Matrix)); //Don't know if this will work, but I'm pretty sure Matrix has constant size; Would be faster;
  this->numRows = b.numRows;
  this->numCols = b.numCols;
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      this->mat[i][j] = b.mat[i][j];
    }
  }
}

Matrix Matrix::matrixAdd(const Matrix &m2, const bool &toPrint) const { //don't add two of the same size;
  if (this->numCols != m2.numCols) {
    std::cerr << additionSizeError;
    return Matrix(0,0);
  } else if (this->numRows != m2.numRows) {
    std::cerr << additionSizeError;
    return Matrix(0,0);
  } else {
    Matrix returnable = Matrix(*this); //TODO: replace this with algorithms::transform;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; i < numCols; j++) {
        returnable.mat[i][j] += m2.mat[i][j];
      }
    }
    
    if (toPrint) {
      std::cout << "The matrix:\n";
      print();
      std::cout << "added to the matrix:\n";
      m2.print();
      std::cout << "is:\n";
      returnable.print();
    }
    return returnable;
  }
}

Matrix Matrix::elementAdd(const double& c, const bool& toPrint) const {
  Matrix returnable = Matrix(*this);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; i < numCols; j++) {
      returnable.mat[i][j] += c;
    }
  }
  
  if (toPrint) {
    std::cout << "The element: " << c << "added to the matrix:\n";
    print();
    std::cout << "is:\n";
    returnable.print();
  }
  
  return returnable;
}

Matrix Matrix::matrixMultiply(const Matrix& m2, const bool inFront, const bool& toPrint = 0) const { // inFront = 1 if this*m2, inFront = 0 if m2*this, default to this*m2 if no argument is given;
  const Matrix *first = NULL;
  const Matrix *second = NULL;
  // Check size on multiply;
  if (inFront) {
    if (this->numCols == m2.numRows) {
      first = this;
      second = &m2;
    } else {
      std::cerr << multiplySizeError;
      return Matrix(0,0);
    }
  } else {
    if (m2.numRows == this->numCols) {
      first = &m2;
      second = this;
    } else {
      std::cerr << multiplySizeError;
      return Matrix(0,0);
    }
  }
  
  /* The commented lines shouldn't be necessary because the function should
   * exit without returning anything if the conditions don't hold;
   */
  
//  if (first != NULL) {
//    if (second != NULL) {
  Matrix returnable(first->numRows, second->numCols);
  double tempDouble;
  for (int i = 0; i < first->numRows; i++) {
    for (int j = 0; j < second->numCols; j++) {
      tempDouble = 0;
      for (int k = 0; k < first->numCols; k++) {
        tempDouble += first->mat[i][k]*second->mat[k][j];
      }
      returnable.mat[i][j] = tempDouble;
    }
  }
  
  if (toPrint) {
    std::cout << "The matrix:\n";
    first->print();
    std::cout << "multiplied by the matrix:\n";
    second->print();
    std::cout << "is:\n";
    returnable.print();
  }
  
  return returnable;
    
}

Matrix Matrix::elementMultiply(const double& c, const bool& toPrint = 0) const {
  Matrix returnable = Matrix(*this);
  
  for(int i = 0; i < this->numRows; i++) {
    for (int j = 0; j < this->numCols; j++) {
      returnable.mat[i][j] *= c;
    }
  }
  
  if (toPrint) {
    std::cout << "The constant: " << c << "\nmultiplied by the matrix: \n";
    print();
    std::cout << "is:\n";
    returnable.print();
  }
  
  return returnable;
}

Matrix Matrix::transpose(const bool& toPrint) const {
  Matrix returnable(numCols, numRows, 0);
  for (int i = 0; i < numCols; i++) {
    for (int j = 0; j < numRows; j++) {
      returnable.mat[i][j] = this->mat[j][i];
    }
  }
  
  if (toPrint) {
    std::cout << "The transpose of the matrix:\n";
    print();
    std::cout << "is:\n";
    returnable.print();
  }
  
  return returnable;
}

void Matrix::print() const {
  print(std::cout);
}

void Matrix::print(std::ostream &os) const {
  for (int i = 0; i < this->numRows; i++) {
    for (int j = 0; i < this->numCols; i++) {
      std::cout << std::setprecision(4) << "    " << mat[i][j];
    } std::cout << '\n';
  } std::cout << '\n';
}

