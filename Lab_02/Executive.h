/**
 * @file:   Executive.h
 * @author: Davis St. Aubin
 *
 * Created on September 15, 2013, 11:39 AM
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "Matrix.h"

class Executive {
public:
  const static int maxMatrices = 20;
  /** A constructor that parses MatrixFiles and DirectiveFiles, handling MatrixFiles as directed in DirectiveFiles;
    * @param MatrixFiles  An array containing the file locations of the txt files the input Matrices are stored in; each file should have an integer number of rows followed by an integer number of columns followed by numRows x numCols double elements;
    * @param numMatFiles  The number of strings in MatrixFiles;
    * @param DirectiveFile  The file of directives detailing which operations should be carried out;
    * @pre None
    * @post None
    */
  Executive(std::string MatrixFiles[], int numMatFiles, std::string DirectiveFile);
private:
  Matrix matrices[maxMatrices];
  int getNextInt(std::istream &inputStream, int &toStore);
  int getNextDouble(std::istream &inputStream, double &toStore);
  void nextLine(std::istream &inputStream);
  void parseDirectives(std::string fileName);
  void parseMatrixFile(std::string &fileName, int &k);
};

