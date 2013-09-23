#include "Polynomial.h"

/** 
 * 
 */
Polynomial::Polynomial() : length(MAX_DEGREE), printable(""), PRINT_PRECISION(5), sum(0) {
    std::fill(this->coefficients, this->coefficients + MAX_DEGREE, 0);
}

/** 
 * 
 */
Polynomial::Polynomial(double coefficients[], int order = MAX_DEGREE-1) : length(order+1), printable(""), PRINT_PRECISION(5), sum(0) {
    std::fill(this->coefficients, this->coefficients + MAX_DEGREE, 0);
    for (int i = 0; i < length; i++) {
        this->coefficients[i] = coefficients[i];
    }
}

/** 
 * 
 */
Polynomial Polynomial::add(Polynomial p2, const bool toPrint = 0) {
    double tempCoeff[MAX_DEGREE] = {0};
    
    for(int i = 0; i < std::max(this->length, p2.length); i++) {
        tempCoeff[i] += p2.coefficients[i] + coefficients[i];
    }

    Polynomial returnable(tempCoeff, std::max(this->length, p2.length)-1);

    if (toPrint) {
        std::cout << "\nThe sum of the polynomials,\n ";
        print(); std::cout << " and "; p2.print();
        std::cout << " is "; returnable.print();
    }

    return returnable;
}

/** 
 * 
 */
Polynomial Polynomial::differentiate(const bool toPrint = 0) {
    double tempCoeff[MAX_DEGREE] = {0};

    for(int i = 0; i < this->length - 1; i++) {
        tempCoeff[i] = (i+1)*this->coefficients[i+1];
    }

    Polynomial returnable(tempCoeff, this->length-1);

    if (toPrint) {
        std::cout << "\nThe derivative of the polynomial,\n ";
        print(); std::cout << " is ";
        returnable.print();
    }

    return returnable;
}

/** 
 * 
 */
double Polynomial::evaluate(const double x, const bool toPrint = 0) {
    if (sum == 0) {
        for (int i = 0; i < this->length; i++) {
            sum += this->coefficients[i]*std::pow(x,i);
        }
    }

    if (toPrint) {
        std::cout << "\nThe polynomial,\n ";
        print();
        std::cout << std::setprecision(PRINT_PRECISION) << " evaluated at " << x << "\n is " << sum << ".\n";
    }

    return sum;
}

/** 
 * 
 */
void Polynomial::print() {

    int counter = 1;
    
    if (this->coefficients[0] != 0) {
        std::cout << std::setprecision(PRINT_PRECISION) << this ->coefficients[0] << " + ";
    } 
    while (this->coefficients[counter] == 0) {
        ++counter;
    } std::cout << std::setprecision(PRINT_PRECISION) << this->coefficients[counter] << "x^" << counter;
    ++counter;
    for (; counter < length; counter++) {
        if (this->coefficients[counter] != 0) {
            std::cout << std::setprecision(PRINT_PRECISION) << " + " << this->coefficients[counter] << "x^" << counter;
        }
    } 
    if (counter < length && this->coefficients[counter] != 0) {
        std::cout << std::setprecision(PRINT_PRECISION) << this->coefficients[length] << "x^" << length;
    } std::cout << '\n';
}

