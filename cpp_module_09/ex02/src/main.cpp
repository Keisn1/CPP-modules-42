#include "PMergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    (void)argv;
    std::cout << argc - 1 << std::endl;
    return 0;
}
