#include "PMergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    MergeVector mVec;
    int count = 1;
    while (count < argc) {
        try {
            mVec.push(argv[count++]);
        } catch (MergeVector::InvalidValException& e) {
            std::cout << "Error" << std::endl;
            return 1;
        }
    }
    std::cout << "Before:";
    mVec.print();
    std::cout << std::endl;

    mVec.sort();

    std::cout << "After:";
    mVec.print();
    std::cout << std::endl;
    return 0;
}
