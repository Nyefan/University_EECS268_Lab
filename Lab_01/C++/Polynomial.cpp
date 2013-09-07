#include "Polynomial.h"

Polynomial::Polynomial() : order(MAX_DEGREE), printable(""), sum(0) {
    std::fill(this->coefficients, this->coefficients + MAX_DEGREE, 0);
}

Polynomial::Polynomial(double coefficients[], int order = MAX_DEGREE) : order(order), printable(""), sum(0) {
    std::fill(this->coefficients, this->coefficients + MAX_DEGREE, 0);
    std::copy(coefficients, coefficients + sizeof(coefficients)/sizeof(double), this->coefficients);
}

Polynomial Polynomial::add(Polynomial p2, const bool toPrint = 0) {
    double tempCoeff[MAX_DEGREE] = {0};
    
    for(int i = 0; i < this->order; i++) {
        tempCoeff[i] += p2.coefficients[i] + coefficients[i];
    }

    Polynomial returnable(tempCoeff, std::max(this->order, p2.order));

    if (toPrint) {
        std::cout << "\nThe sum of the polynomials,\n";
        print(); std::cout << " and "; p2.print();
        std::cout << "\n is "; returnable.print();
    }

    return returnable;
}

Polynomial Polynomial::differentiate(const bool toPrint = 0) {
    double tempCoeff[MAX_DEGREE] = {0};

    for(int i = 0; i < this->order - 1; i++) {
        tempCoeff[i] = (i+1)*this->coefficients[i+1];
    }

    Polynomial returnable(tempCoeff, this->order-1);

    if (toPrint) {
        std::cout << "\nThe derivative of the polynomial,\n";
        print(); std::cout << " is ";
        returnable.print();
    }

    return returnable;
}

double Polynomial::evaluate(const double x, const bool toPrint = 0) {
    if (sum == 0) {
        for (int i = 0; i < this->order; i++) {
            sum += this->coefficients[i]*std::pow(x,i);
        }
    }

    if (toPrint) {
        std::cout << "\nThe polynomial,\n";
        print();
        std::cout << " evaluated at " << x << "\n is " << floor(sum + 0.5) << ".";
    }

    return sum;
}

void Polynomial::print() {
    if (printable != "") {
        std::cout << printable << "\n";
    } else {
        parseCoefficients();
        std::cout << printable << "\n";
    }
}

void Polynomial::parseCoefficients() {
    printable = "";
    printable += std::to_string(floor(this->coefficients[0] + 0.5));
    for (int i = 1; i < order - 1; i++) {
        double tempDouble = this->coefficients[i];
        if(tempDouble != 0) {
            printable += " + " + std::to_string(std::floor(tempDouble + 0.5)) + "x^" + std::to_string(i);
        }
    }
}

