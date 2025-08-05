#ifndef RPN_H
#define RPN_H

#include <cctype>
#include <stack>

class RPN {
  private:
    std::stack< int > _stack;

    bool isOperation(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '/')
            return true;
        return false;
    }

    bool isValidChar(char c) {
        if (c == ' ' || c == '+' || c == '-' || c == '*' || c == '/')
            return true;
        if (std::isdigit(c))
            return true;
        return false;
    }

  public:
    void eat(char c) {
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
    int result() {
        if (_stack.size() != 1)
            throw InvalidException();
        return _stack.top();
    }

    class InvalidException : public std::exception {
      public:
        const char* what() const throw() { return "invalid sequence"; }
    };
};

#endif // RPN_H
