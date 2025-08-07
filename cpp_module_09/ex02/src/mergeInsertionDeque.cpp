#include "PMergeMe.hpp"
#include <deque>

std::deque< int > buildSecondaryDeque(std::deque< int > main, std::deque< std::pair< int, int > > secondaryPairs) {
    std::deque< int > secondary;
    while (main.size()) {
        int value = main.back();
        std::deque< std::pair< int, int > >::iterator itPair = secondaryPairs.begin();
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

void buildMainAndSecondaryChainDeque(std::deque< int > values, std::deque< int >& mainChain,
                                     std::deque< int >& secondary) {

    int remaining = -1;
    if (values.size() % 2) {
        remaining = values.back();
        values.pop_back();
    }

    std::deque< std::pair< int, int > > secondaryPairs;
    std::deque< int >::iterator it = values.begin();
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

    mainChain = mergeInsertionDeque(mainChain);
    secondary = buildSecondaryDeque(mainChain, secondaryPairs);
    if (remaining != -1)
        secondary.push_back(remaining);

    mainChain.push_front(secondary.front());
    return;
}

void insertSecondaryIntoMainChainDeque(std::deque< int >& mainChain, std::deque< int >& secondary) {
    int n = 3;
    while (secondary.size() > jacobsthal(n - 1)) {
        unsigned int idx = secondary.size() < jacobsthal(n) ? (secondary.size() - 1) : (jacobsthal(n) - 1);
        while (idx > (jacobsthal(n - 1) - 1)) {
            std::deque< int >::iterator itbegin = std::next(secondary.begin(), idx);
            binaryInsertDeque(mainChain, *itbegin);
            idx--;
        }
        n++;
    }
}

std::deque< int > mergeInsertionDeque(std::deque< int > values) {
    int size = values.size();
    if (size <= 1)
        return values;

    std::deque< int > mainChain;
    std::deque< int > secondary;
    buildMainAndSecondaryChainDeque(values, mainChain, secondary);
    insertSecondaryIntoMainChainDeque(mainChain, secondary);

    return mainChain;
}
