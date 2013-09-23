/** 
 * @file:   Executive.cpp
 * @author: Davis St. Aubin
 * 
 * Created on September 15, 2013, 11:39 AM
 */

#include "Executive.h"

Executive::Executive(std::string MatrixFiles[], int numMatFiles, std::string DirectiveFile) {
  for (int i = 0; i < numMatFiles; i++) {
    parseMatrixFile(MatrixFiles[i], i);
  }
  parseDirectives(DirectiveFile);
}

void Executive::parseMatrixFile(std::string &fileName, int &k) {
  
  const char* c_fileName = fileName.c_str();
  std::ifstream inputFile(c_fileName);

  int tempRows = 0;
  int tempCols = 0;
  getNextInt(inputFile, tempRows);
  getNextInt(inputFile, tempCols);

  double tempArray[100][100];
  
  for (int i = 0; i < tempRows; i++) {
    for (int j = 0; j < tempCols; j++) {
      getNextDouble(inputFile, tempArray[i][j]);
    }
  } this->matrices[k] = Matrix(tempRows, tempCols, tempArray);

  inputFile.close();
}

void Executive::parseDirectives(std::string fileName) {
    const char* c_fileName = fileName.c_str();
    std::ifstream inputFile(c_fileName);

    while (!inputFile.eof()) {
        std::string command  = "";
        inputFile >> command;
        int matToOperate;
        getNextInt(inputFile, matToOperate);

        if (command == "matrixAdd") {
          int matrixToAdd;
          getNextInt(inputFile, matrixToAdd);
          matrices[matToOperate].matrixAdd(matrices[matrixToAdd], true);
        } else if (command == "elementAdd") {
          double elementToAdd;
          getNextDouble(inputFile, elementToAdd);
          matrices[matToOperate].elementAdd(elementToAdd, true);
        } else if (command == "matrixMultiply") {
          int matrixToMultiply;
          getNextInt(inputFile, matrixToMultiply);
          matrices[matToOperate].matrixMultiply(matrices[matrixToMultiply], true, true);
        } else if (command == "elementMultiply") {
          double elementToMultiply;
          getNextDouble(inputFile, elementToMultiply);
          matrices[matToOperate].elementMultiply(elementToMultiply, true);
        } else if (command == "transpose") {
          int matrixToTranspose;
          getNextInt(inputFile, matrixToTranspose);
          matrices[matToOperate].transpose(true);
        } else if (inputFile.eof()) {
            break;
        } else {
            std::cerr << "Unknown or unsupported directive operation.";
            nextLine(inputFile);
        }
    }

    inputFile.close();
}

//bool Executive::throwsErrors(int checkVar, std::istream& inputFile, int polyNum) {
//    if (checkVar == 0) {
//        std::cerr << "Input file is improperly formatted at polynomial " << polyNum << ".\nThe parser will now skip to the next line beginning with an int.\n";
//        nextLine(inputFile);
//        return true;
//    } else if (checkVar == -1) {
//        std::cerr << "Unexpected End of File\n";
//        return true;
//    } else {
//        return false;
//    }
//}

void Executive::nextLine(std::istream& inputStream) {
    char tempChar;
    do {
        tempChar = inputStream.get();
    } while (tempChar != '\n' && !inputStream.eof());
}

int Executive::getNextDouble(std::istream &inputStream, double &toStore) {
    if (inputStream >> toStore) {
        return 1;
    } else {
        inputStream.clear();
        if (inputStream.eof()) {
            return -1;
        } else {
            inputStream.clear();
            return 0;
        }
    }
}

int Executive::getNextInt(std::istream &inputStream, int &toStore) {
    if (inputStream >> toStore) {
        return 1;
    } else if (inputStream.eof()) {
        return -1;
    } else {
        inputStream.clear();
        return 0;
    }
}

