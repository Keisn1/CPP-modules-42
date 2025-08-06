#include "PMergeMe.hpp"
#include <iostream>
#include <list>

std::list< int > buildSecondaryList(std::list< int > main, std::list< std::pair< int, int > > secondaryPairs) {
    std::list< int > secondary;
    while (main.size()) {
        int value = main.back();
        std::list< std::pair< int, int > >::iterator itPair = secondaryPairs.begin();
        while (itPair != secondaryPairs.end()) {
            if ((*itPair).second == value) {
                secondary.push_front((*itPair).first);
                itPair = secondaryPairs.erase(itPair); // erase returns next valid iterator
            } else {
                itPair++;
            }
        }
        main.pop_back();
    }
    return secondary;
}

unsigned int jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::list< int > mergeInsertionList(std::list< int > values) {
    int size = values.size();
    if (size == 1)
        return values;

    std::list< int > mainChain;
    std::list< std::pair< int, int > > secondaryPairs;
    int remaining = -1;

    if (values.size() % 2) {
        remaining = values.back();
        values.pop_back();
    }

    std::list< int >::iterator it = values.begin();
    while (it != values.end()) {
        int val1 = *it++;
        int val2 = *it++;
        if (val1 < val2) {
            mainChain.push_back(val2);
            secondaryPairs.push_back(std::pair< int, int >(val1, val2));
        } else {
            mainChain.push_back(val1);
            secondaryPairs.push_back(std::pair< int, int >(val2, val1));
        }
    }

    mainChain = mergeInsertionList(mainChain);
    std::list< int > secondary = buildSecondaryList(mainChain, secondaryPairs);
    if (remaining != -1)
        secondary.push_back(remaining);
    mainChain.push_front(secondary.front());

    if (secondary.size() == 1)
        return mainChain;

    int steps = secondary.size() < 3 ? (secondary.size() - 1) : (3 - 1);

    while (steps > 0) {
        std::list< int >::iterator itbegin = std::next(secondary.begin(), steps);
        binaryInsertList(mainChain, *itbegin);
        steps--;
    }

    if (secondary.size() <= 3) {
        return mainChain;
    }

    steps = secondary.size() < 5 ? (secondary.size() - 1) : (5 - 1);

    while (steps > 5 - 3) {
        std::list< int >::iterator itbegin = std::next(secondary.begin(), steps);
        binaryInsertList(mainChain, *itbegin);
        steps--;
    }

    // if (secondary.size() == 2) {
    //     std::list< int >::iterator itbegin = std::next(secondary.begin(), 1);
    //     binaryInsertList(mainChain, *itbegin);
    //     return mainChain;
    // }

    // if (secondary.size() > 2) {
    //     std::list< int >::iterator itbegin = std::next(secondary.begin(), 2);
    //     binaryInsertList(mainChain, *itbegin--);
    //     binaryInsertList(mainChain, *itbegin);
    // }

    return mainChain;
}
