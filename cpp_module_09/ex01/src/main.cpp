#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "wrong number of arguemnts" << std::endl;
    }
    std::string input(argv[1]);
    std::string::iterator it = input.begin();

    RPN rpn;
    while (it != input.end()) {
        try {
            rpn.eat(*it++);
        } catch (RPN::InvalidException& e) {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }
    try {
        std::cout << rpn.result() << std::endl;
    } catch (RPN::InvalidException& e) {
        std::cerr << "Error" << std::endl;
    }

    return 0;
}
