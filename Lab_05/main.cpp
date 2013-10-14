#include <iostream>

#include "Knights_Tour.h"

int main(int argc, char* argv) {
    
    Knights_Tour tour = Knights_Tour(5,5,0,0);

    if(tour.findPath()) {
        std::cout << "valid path found\n";
    } else {std::cout << "no path found\n";}
    tour.print();

    return 0;

}