#ifndef RPN_H
#define RPN_H

#include <stack>

class RPN {
  private:
    std::stack< int > _stack;
    bool isOperation(char c);
    bool isValidChar(char c);

  public:
    RPN();
    ~RPN();
    RPN(const RPN&);
    RPN& operator=(const RPN&);
    void eat(char c);
    int result();

    class InvalidException : public std::exception {
      public:
        const char* what() const throw();
    };
};

#endif // RPN_H
