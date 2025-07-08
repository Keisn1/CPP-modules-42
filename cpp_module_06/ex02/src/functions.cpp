#include "Base.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void) {
    std::srand(std::time(NULL)); // use current time as seed for random generator
    int random_value = std::rand() % 3;
    switch (random_value) {
    case 0:
        std::cout << "generated A" << std::endl;
        return new A;
    case 1:
        std::cout << "generated B" << std::endl;
        return new B;
    case 2:
        std::cout << "generated C" << std::endl;
        return new C;
    }
    return NULL;
}

void identify(Base* p) {
    A* a = dynamic_cast< A* >(p);
    if (a) {
        std::cout << "A" << std::endl;
    }
    B* b = dynamic_cast< B* >(p);
    if (b) {
        std::cout << "B" << std::endl;
    }
    C* c = dynamic_cast< C* >(p);
    if (c) {
        std::cout << "C" << std::endl;
    }
};

void identify(Base& p) {
    A* a = dynamic_cast< A* >(&p);
    if (a) {
        std::cout << "A" << std::endl;
    }
    B* b = dynamic_cast< B* >(&p);
    if (b) {
        std::cout << "B" << std::endl;
    }
    C* c = dynamic_cast< C* >(&p);
    if (c) {
        std::cout << "C" << std::endl;
    }
};
