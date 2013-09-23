#include "Executive.h"

Executive::Executive(std::string args[2]) {
    parsePolynomials(args[0]);
    parseDirectives(args[1]);
}

void Executive::parsePolynomials(std::string fileName) {
 /* DEBUGGING POLYNOMIAL SET:
    double temp[] = {1.3, 4.3, 2.35, 6.5, 2.4};
    polynomials[0] = Polynomial(temp, 4);
    polynomials[0].print();
    double temp2[] = {2.5, 30.0, 4.390, 5.3};
    polynomials[1] = Polynomial(temp2, 3);
    polynomials[1].print();
    double temp3[] = {6.2, 5.45, 4.8, 6.5, 21, 4.2};
    polynomials[2] = Polynomial(temp3, 5);
    polynomials[2].print();
    double temp4[] = {3.5, 7.8, 9.5, 4.2, 1.5, 3.2, 6.4};
    polynomials[3] = Polynomial(temp4, 6);
    polynomials[3].print();
    double temp5[] = {3.5, 9.8, 4.80};
    polynomials[4] = Polynomial(temp5, 2);
    polynomials[4].print();
    END_DEBUGGING;
    */

    std::ifstream inputFile(fileName);
    int polyNum = 0;

    while (!inputFile.eof()) {
        if (polyNum >= MAX_POLYNOMIAL) {
            std::string tempString = std::to_string(MAX_POLYNOMIAL);
            std::cerr << "Input file has more than " + tempString + " polynomials.  Only the first " + tempString + " will be processed.\n";
            break;
        }

        int tempSize = 0;
        getNextInt(inputFile, tempSize);

        if(inputFile.eof()) {break;}

        double tempArray[MAX_DEGREE] = {0};
        for (int i = 0; i <= tempSize; i++) {
            getNextDouble(inputFile, tempArray[i]);
        } polynomials[polyNum++] = Polynomial(tempArray, tempSize);

        // DEBUGGING:
        // polynomials[polyNum-1].print();
        // END DEBUGGING;
    }

    inputFile.close();

    //std::ifstream inputFile(fileName);
    //int polyNum = 0;

    //while (!inputFile.eof()) {
    //    if (polyNum >= MAX_POLYNOMIAL) {
    //        std::string tempString = std::to_string(MAX_POLYNOMIAL);
    //        std::cerr << "Input file has more than " + tempString + " polynomials.  Only the first " + tempString + "will be processed.\n";
    //    }

    //    int tempSize = 0;
    //    if (throwsErrors(getNextInt(inputFile, tempSize), inputFile, polyNum)) {
    //        break;
    //    } else {
    //        double tempArray[MAX_DEGREE];
    //        bool shouldAssign = true;
    //        for (int i = 0; i <= tempSize; i++) {
    //            if (throwsErrors(getNextDouble(inputFile, tempArray[i]), inputFile, polyNum)) {
    //                shouldAssign = false;
    //                break;
    //            }
    //        } if (shouldAssign) {
    //            polynomials[polyNum++] = Polynomial(tempArray, tempSize);

    //            // Debugging:
    //            polynomials[polyNum].print();
    //            // End Debugging;
    //        }
    //        std::cout << '\n';
    //    }
    //}

    //inputFile.close();
}

void Executive::parseDirectives(std::string fileName) {
    std::ifstream inputFile(fileName);

    while (!inputFile.eof()) {
        std::string command  = "";
        inputFile >> command;
        int polyToOperate;
        getNextInt(inputFile, polyToOperate);

        if (command == "add") {
            int polyToAdd;
            getNextInt(inputFile,polyToAdd);
            polynomials[polyToOperate].add(polynomials[polyToAdd], true);
        } else if (command == "differentiate") {
            polynomials[polyToOperate].differentiate(true);
        } else if (command == "evaluate") {
            double x;
            getNextDouble(inputFile,x);
            polynomials[polyToOperate].evaluate(x,true);
        } else if (command == "print") {
            polynomials[polyToOperate].print();
        } else if (inputFile.eof()) {
            break;
        } else {
            std::cerr << "Unknown or unsupported directive operation.";
            nextLine(inputFile);
        }
    }

    inputFile.close();
}

bool Executive::throwsErrors(int checkVar, std::istream& inputFile, int polyNum) {
    if (checkVar == 0) {
        std::cerr << "Input file is improperly formatted at polynomial " << polyNum << ".\nThe parser will now skip to the next line beginning with an int.\n";
        nextLine(inputFile);
        return true;
    } else if (checkVar == -1) {
        std::cerr << "Unexpected End of File\n";
        return true;
    } else {
        return false;
    }
}

void Executive::nextLine(std::istream& inputStream) {
    char tempChar;
    do {
        tempChar = inputStream.get();
    } while (tempChar != '\n' && !inputStream.eof());
}

int Executive::getNextDouble(std::istream& inputStream, double& toStore) {
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

int Executive::getNextInt(std::istream& inputStream, int& toStore) {
    if (inputStream >> toStore) {
        return 1;
    } else if (inputStream.eof()) {
        return -1;
    } else {
        inputStream.clear();
        return 0;
    }
}
