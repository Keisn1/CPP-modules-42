#include "PMergeMe.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::list< int > listC;
    std::deque< int > dequeC;

    int count = 1;
    while (count < argc) {
        int val = std::atoi(argv[count++]);
        if (val < 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        listC.push_front(val);
        dequeC.push_front(val);
    }

    int size = listC.size();
    std::cout << "Before: ";
    for (std::list< int >::iterator it = listC.begin(); it != listC.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t start = clock();
    std::list< int > gotList = mergeInsertionList(listC);
    clock_t end = clock();
    double timeList = double(end - start) / CLOCKS_PER_SEC * 1000.0;

    start = clock();
    std::deque< int > gotDeque = mergeInsertionDeque(dequeC);
    end = clock();
    double timeDeque = double(end - start) / CLOCKS_PER_SEC * 1000.0;

    std::cout << "After: ";
    for (std::list< int >::iterator it = gotList.begin(); it != gotList.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << size << " elements with std::list : " << timeList << " us"
              << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque : " << timeDeque << " us"
              << std::endl;
    return 0;
}
