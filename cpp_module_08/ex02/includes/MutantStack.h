#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>

template < typename T >
class MutantStack {
  private:
    std::stack< T > _stack;

  public:
    MutantStack(void) : _stack(std::stack< T >()) {};
    ~MutantStack(void) {};
    MutantStack(const MutantStack< T >& other) : _stack(other._stack) {};
    MutantStack< T >& operator=(const MutantStack< T >& other) {
        if (*this == other) {
            return *this;
        }
        this->_stack = other._stack;
        return *this;
    };
};

#endif // MUTANTSTACK_H
