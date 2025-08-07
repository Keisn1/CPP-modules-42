#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other) {
    if (this == &other)
        return *this;
    _stack = other._stack;
    return *this;
}

bool RPN::isOperation(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

bool RPN::isValidChar(char c) {
    if (c == ' ' || c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    if (std::isdigit(c))
        return true;
    return false;
}
void RPN::eat(char c) {
    if (!isValidChar(c))
        throw InvalidException();

    if (c == ' ')
        return;

    if (std::isdigit(c))
        _stack.push(c - '0');

    if (isOperation(c)) {
        if (_stack.size() < 2)
            throw InvalidException();

        int rVal = _stack.top();
        _stack.pop();
        int lVal = _stack.top();
        _stack.pop();
        if (c == '+') {
            _stack.push(lVal + rVal);
        } else if (c == '-') {
            _stack.push(lVal - rVal);
        } else if (c == '*') {
            _stack.push(lVal * rVal);
        } else if (c == '/') {
            if (rVal == 0)
                throw InvalidException();
            _stack.push(lVal / rVal);
        }
    }
}
int RPN::result() {
    if (_stack.size() != 1)
        throw InvalidException();
    return _stack.top();
}

const char* RPN::InvalidException::what() const throw() { return "invalid sequence"; }
