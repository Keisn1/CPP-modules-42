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
                itPair = secondaryPairs.erase(itPair); // erase returns next valid iterator
            } else {
                itPair++;
            }
        }
        main.pop_back();
    }
    return secondary;
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

    binaryInsertList(mainChain, secondary.back());
    secondary.pop_front();
    if (remaining != -1)
        binaryInsertList(mainChain, remaining);
    return mainChain;
}
