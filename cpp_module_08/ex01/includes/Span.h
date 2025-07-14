#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
  private:
    unsigned int N;
    std::vector< int > arr;

  public:
    Span(void) : N(0) {};
    Span(unsigned int n) : N(n) {};
    Span(const Span&) {};
    ~Span(void) {};
    Span& operator=(const Span&) { return *this; };
    void addNumber(int nbr) {
        if (arr.size() == N) {
            throw SpanIsFullException();
        }
        arr.push_back(nbr);
    };

    template < typename Iterator >
    void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + arr.size() >= N) {
            throw SpanIsFullException();
        }
        arr.insert(arr.end(), begin, end);
    };

    int shortestSpan() {
        if (arr.size() < 2)
            return 0;

        std::vector< int > sorted = arr;
        std::sort(sorted.begin(), sorted.end());

        int minSpan = sorted[1] - sorted[0];
        for (size_t i = 1; i < sorted.size(); i++) {
            int span = sorted[i] - sorted[i - 1];
            if (span < minSpan)
                minSpan = span;
        }
        return minSpan;
    };

    int longestSpan() {
        if (arr.size() < 2)
            return 0;

        int minVal = *std::min_element(arr.begin(), arr.end());
        int maxVal = *std::max_element(arr.begin(), arr.end());
        return maxVal - minVal;
    };

    class SpanIsFullException : public std::exception {
      public:
        const char* what() const throw() { return "Span is full"; }
    };
};

#endif // SPAN_H
