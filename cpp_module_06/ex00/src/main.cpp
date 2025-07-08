#include "ScalarConverter.h"
#include <cstdlib>
#include <iostream>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "need exactly one argument" << std::endl;
        exit(1);
    }
    std::string str(argv[1]);

    ScalarConverter::convert(str);
    return 0;
}
