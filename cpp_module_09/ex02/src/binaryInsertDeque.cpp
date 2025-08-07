#include <deque>
#include <iterator>

std::deque< int >::iterator findPlaceDeque(std::deque< int >::iterator begin, std::deque< int >::iterator end,
                                           int val) {
    if (begin == end)
        return begin;

    std::deque< int >::iterator temp = end;
    --temp;
    if (begin == temp) {
        if (val < *begin)
            return begin;
        else
            return end;
    }

    std::deque< int >::iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);
    if (val == *middle)
        return middle;
    if (val < *middle)
        return findPlaceDeque(begin, middle, val);
    else
        return findPlaceDeque(++middle, end, val);
};

void binaryInsertDeque(std::deque< int >& l, int val) { l.insert(findPlaceDeque(l.begin(), l.end(), val), val); };
