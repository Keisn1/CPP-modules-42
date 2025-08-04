#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <iterator>
#include <vector>

class Span {
  private:
    unsigned int _N;
    std::vector< int > _arr;

  public:
    typedef typename std::vector< int >::iterator iterator;

    Span(void) : _N(0) {};
    Span(unsigned int n) : _N(n) {};
    Span(const Span& other) : _N(other._N), _arr(other._arr) {};
    ~Span(void) {};

    Span& operator=(const Span& other) {
        if (this == &other)
            return *this;
        _N = other._N;
        _arr = other._arr;
        return *this;
    };

    void addNumber(int nbr) {
        if (_arr.size() == _N) {
            throw SpanIsFullException();
        }
        _arr.push_back(nbr);
    };

    template < typename Iterator >
    void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _arr.size() > _N) {
            throw SpanIsFullException();
        }
        _arr.insert(_arr.end(), begin, end);
    };

    unsigned int shortestSpan() const {
        if (_arr.size() < 2)
            return 0;

        std::vector< int > sorted = _arr;
        std::sort(sorted.begin(), sorted.end());

        long long minSpan = static_cast< long long >(sorted[1]) - static_cast< long long >(sorted[0]);
        for (size_t i = 2; i < sorted.size(); i++) {
            long long span = static_cast< long long >(sorted[i]) - static_cast< long long >(sorted[i - 1]);
            if (span < minSpan)
                minSpan = span;
        }
        return static_cast< unsigned int >(minSpan);
    };

    unsigned int longestSpan() const {
        if (_arr.size() < 2)
            return 0;

        long long minVal = static_cast< long long >(*std::min_element(_arr.begin(), _arr.end()));
        long long maxVal = static_cast< long long >(*std::max_element(_arr.begin(), _arr.end()));
        return static_cast< unsigned int >(maxVal - minVal);
    };

    class SpanIsFullException : public std::exception {
      public:
        const char* what() const throw() { return "Span is full"; }
    };
};

#endif // SPAN_H
