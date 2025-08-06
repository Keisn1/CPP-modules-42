#ifndef PMERGEME_H
#define PMERGEME_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

class MergeVector {
  private:
    std::vector< int > _vec;

  public:
    MergeVector() {};
    void push(char* valStr) {
        int val = std::atoi(valStr);
        if (val < 0)
            throw InvalidValException();
        _vec.push_back(val);
    }
    void print() {
        for (std::vector< int >::iterator it = _vec.begin(); it != _vec.end(); it++)
            std::cout << " " << *it;
    }

    void sort() { std::sort(_vec.begin(), _vec.end()); }

    class InvalidValException : public std::exception {
      public:
        const char* what() const throw() { return "invalid value"; }
    };
};

#endif // PMERGEME_H
