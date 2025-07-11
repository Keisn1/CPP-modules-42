#include "Array.h"
#include <exception>
#include <iostream>
#include <limits>

class TestClass {
  private:
    int n;

  public:
    TestClass() : n(1) {};
    ~TestClass() {};
    void print() { std::cout << n; }
};

int main() {
    {
        std::cout << "(TEST 1)" << std::endl;
        std::cout << "Construct a new array with no parameter and different types" << std::endl;
        {
            Array< char >* a = new Array< char >();
            delete a;
        }
        {
            Array< int >* a = new Array< int >();
            delete a;
        }
        {
            Array< std::string >* a = new Array< std::string >();
            delete a;
        }
        {
            Array< TestClass >* a = new Array< TestClass >();
            delete a;
        }
    }
    {
        std::cout << "(TEST 2)" << std::endl;
        std::cout << "Construct a new array with parameter n and different types" << std::endl;
        std::cout << "Then print the default values of the parameter" << std::endl;
        {
            Array< char >* a = new Array< char >(10);
            std::cout << static_cast< int >((*a)[0]) << std::endl;
            delete a;
        }
        {
            Array< int >* a = new Array< int >(10);
            for (size_t i = 0; i < a->size(); i++) {
                std::cout << (*a)[0] << std::endl;
            }
            delete a;
        }
        {
            // try {
            //     Array< std::string >* a = new Array< std::string >(std::numeric_limits< unsigned int >::max());
            //     delete a;
            // } catch (std::exception& e) {
            //     std::cerr << e.what() << std::endl;
            // }
        }
        {
            Array< TestClass >* a = new Array< TestClass >(20);
            delete a;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "(TEST 3)" << std::endl;
        std::cout << "Copy construct and look that nothing changes" << std::endl;
        std::cout << "check that changes are present only the changed array" << std::endl;
        {
            Array< char >* a = new Array< char >(10);
            for (size_t i = 0; i < a->size(); i++) {
                (*a)[i] = 'a' + i;
            }
            for (size_t i = 0; i < a->size(); i++) {
                std::cout << static_cast< char >((*a)[i]);
            }
            std::cout << std::endl;
            Array< char > b = Array< char >(*a);
            for (size_t i = 0; i < a->size(); i++) {
                std::cout << static_cast< char >((*a)[i]);
            }
            std::cout << std::endl;
            for (size_t i = 0; i < a->size(); i++) {
                b[i] = 'b' + i;
            }
            for (size_t i = 0; i < a->size(); i++) {
                std::cout << static_cast< char >(b[i]);
            }
            std::cout << std::endl;

            // try {
            //     b[20];
            // } catch (std::exception& e) {
            //     std::cerr << e.what() << std::endl;
            // }
            // try {
            //     b[-20];
            // } catch (std::exception& e) {
            //     std::cerr << e.what() << std::endl;
            // }
            delete a;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "(TEST 4)" << std::endl;
        std::cout << "Copy assignment and look that nothing changes" << std::endl;
        std::cout << "check that changes are present only the changed array" << std::endl;
        Array< char >* a = new Array< char >(10);
        for (size_t i = 0; i < a->size(); i++) {
            (*a)[i] = 'a' + i;
        }
        for (size_t i = 0; i < a->size(); i++) {
            std::cout << static_cast< char >((*a)[i]);
        }
        std::cout << std::endl;

        Array< char > b;
        b = *a;
        delete a;
    }
    return 0;
}
