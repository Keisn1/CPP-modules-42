#include "MutantStack.h"
#include <iostream>
#include <stack>

int main() {
    {
        std::cout << "(TEST 1)" << std::endl;
        std::cout << "Stack default construction" << std::endl;
        {
            std::stack< int > aStack;
            std::stack< int >* aStackp = new std::stack< int >();
            delete aStackp;
        }
        {
            MutantStack< int > aMutant;
            MutantStack< int >* aMutantP = new MutantStack< int >();
            delete aMutantP;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "(TEST 2)" << std::endl;
        std::cout << "Copy Constructor and Copy assignment" << std::endl;
        // {
        // 	MutantStack<int>

        // }
    }
}
