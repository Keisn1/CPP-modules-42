#include "PMergeMe.hpp"
#include <list>

std::list< int > buildSecondaryList(std::list< int > main, std::list< std::pair< int, int > > secondaryPairs) {
    std::list< int > secondary;
    while (main.size()) {
        int value = main.back();
        std::list< std::pair< int, int > >::iterator itPair = secondaryPairs.begin();
        while (itPair != secondaryPairs.end()) {
            if ((*itPair).second == value) {
                secondary.push_front((*itPair).first);
                itPair = secondaryPairs.erase(itPair);
            } else {
                itPair++;
            }
        }
        main.pop_back();
    }
    return secondary;
}

void buildMainAndSecondaryChain(std::list< int > values, std::list< int >& mainChain, std::list< int >& secondary) {
    int remaining = -1;
    if (values.size() % 2) {
        remaining = values.back();
        values.pop_back();
    }

    std::list< std::pair< int, int > > secondaryPairs;
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

    secondary = buildSecondaryList(mainChain, secondaryPairs);
    if (remaining != -1)
        secondary.push_back(remaining);

    mainChain.push_front(secondary.front());
    return;
}

void insertSecondaryIntoMainChain(std::list< int >& mainChain, std::list< int >& secondary) {
    int n = 3;
    while (secondary.size() > jacobsthal(n - 1)) {
        unsigned int idx = secondary.size() < jacobsthal(n) ? (secondary.size() - 1) : (jacobsthal(n) - 1);
        while (idx > (jacobsthal(n - 1) - 1)) {
            std::list< int >::iterator itbegin = secondary.begin();
            std::advance(itbegin, idx);
            binaryInsertList(mainChain, *itbegin);
            idx--;
        }
        n++;
    }
}

std::list< int > mergeInsertionList(std::list< int > values) {
    int size = values.size();
    if (size <= 1)
        return values;

    std::list< int > mainChain;
    std::list< int > secondary;
    buildMainAndSecondaryChain(values, mainChain, secondary);
    insertSecondaryIntoMainChain(mainChain, secondary);

    return mainChain;
}
