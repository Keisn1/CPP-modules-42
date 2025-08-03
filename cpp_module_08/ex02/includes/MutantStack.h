#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <deque>
#include <iostream>
#include <stack>
#include <typeinfo> // for testing purposes

template < typename T, class Container = std::deque< T > >
class MutantStack
    : public std::stack< T, Container > { // without populating the Container, the last test in main will not compile
  public:
    MutantStack(void) {};

    ~MutantStack(void) {};

    MutantStack(const MutantStack< T, Container >& other) : std::stack< T, Container >(other) {};

    MutantStack< T, Container >& operator=(const MutantStack< T, Container >& other) {
        if (this == &other) {
            return *this;
        }
        this->c = other.c;
        return *this;
    };

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }

    // for testing purposes
    void showContainerType() { std::cout << "Container type: " << typeid(this->c).name() << std::endl; }
};

#endif // MUTANTSTACK_H
