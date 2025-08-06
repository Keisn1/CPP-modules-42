#include "PMergeMe.hpp"
#include <iostream>
#include <iterator>

std::list< int >::iterator findPlaceList(std::list< int >::iterator begin, std::list< int >::iterator end, int val) {
    if (begin == end)
        return begin;

    if (begin == std::prev(end)) {
        if (val < *begin)
            return begin;
        else
            return end;
    }

    std::list< int >::iterator middle = std::next(begin, std::distance(begin, end) / 2);
    if (val == *middle)
        return middle;
    if (val < *middle)
        return findPlaceList(begin, middle, val);
    else
        return findPlaceList(++middle, end, val);
};

void binaryInsertList(std::list< int >& l, int val) { l.insert(findPlaceList(l.begin(), l.end(), val), val); };
