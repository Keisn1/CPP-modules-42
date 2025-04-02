#include "ClapTrap.h"
#include <iostream>

#define RESET "\033[0m"
#define DEEPSKYBLUE "\033[38;2;0;191;255m"
#define DARKSALMON "\033[38;2;255;127;80m"
#define DARKVIOLET "\033[38;2;148;0;211m"
#define RED "\033[38;2;255;0;0m"
#define SADDLEBROWN "\033[38;2;139;69;19m"
#define FORESTGREEN "\033[38;2;34;139;34m"

int main() {
    {
        std::cout << DEEPSKYBLUE <<  "Test default constructor" << RESET << std::endl;
        ClapTrap ct ;
        ct.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test string constructor" << RESET << std::endl;
        ClapTrap ct1 ("ct1");
        ct1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy constructor" << RESET << std::endl;
        ClapTrap ct2 ("ct2");
        ClapTrap copy (ct2);
        copy.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy assignment operator" << RESET << std::endl;
        ClapTrap ct2 ("ct2");
        ClapTrap copy;
        copy = ct2;
        copy.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Testing member functions" << RESET << std::endl;
        ClapTrap ct1 ("ct1");
        ct1.printAttributes();
        ct1.takeDamage(5);
        ct1.printAttributes();
        ct1.takeDamage(5);
        ct1.printAttributes();
        ct1.beRepaired(5);
        ct1.printAttributes();
        ct1.takeDamage(3);
        ct1.printAttributes();
        ct1.attack("a target");
        ct1.printAttributes();
        ct1.beRepaired(20);
        ct1.printAttributes();
        ct1.takeDamage(25);
        ct1.printAttributes();

        ct1.beRepaired(2);
        ct1.beRepaired(2);
        ct1.beRepaired(2);
        ct1.beRepaired(2);
        ct1.beRepaired(2);
        ct1.printAttributes();
        ct1.beRepaired(2);
        ct1.printAttributes();
        ct1.beRepaired(2);
        ct1.printAttributes();
        ct1.beRepaired(2);
        ct1.printAttributes();
    }
    return 0;
}
