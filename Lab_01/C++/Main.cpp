#include <string>
#include <Executive.h>

    int main(int argc, char** argv) {

        std::string polyName = "D:\\Immutables\\Dropbox\\Coding\\EECS268\\Lab_01\\Lab01Polynomial.txt";
        std::string directiveName = "D:\\Immutables\\Dropbox\\Coding\\EECS268\\Lab_01\\Lab01Directives.txt";

        std::string newArgs[2];
        newArgs[0] = polyName;
        newArgs[1] = directiveName;

        Executive overSeer(newArgs);
    }