#include <string>
#include <Executive.h>

    int main(int argc, char** argv) {

        std::string polyName = "C:\\Users\\Nyefan\\Documents\\GitHub\\University_EECS268_Lab\\Lab_01\\C++\\Lab01Polynomial.txt";
        std::string directiveName = "C:\\Users\\Nyefan\\Documents\\GitHub\\University_EECS268_Lab\\Lab_01\\C++\\Lab01Directives.txt";

        std::string newArgs[2];
        newArgs[0] = polyName;
        newArgs[1] = directiveName;

        Executive overSeer(newArgs);
    }