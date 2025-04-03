#include "ScavTrap.h"
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
        ScavTrap st1;
        st1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test string constructor" << RESET << std::endl;
        ScavTrap st1 ("st1");
        st1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy constructor" << RESET << std::endl;
        ScavTrap st1 ("st1");
        ScavTrap st2 (st1);
        st1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy assignment constructor" << RESET << std::endl;
        ScavTrap st1 ("st1");
        ScavTrap st2 ("st2");
        st2 = st1;
        st2.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test other member functions" << RESET << std::endl;
        ScavTrap st1 ("st1");
        st1.printAttributes();
        st1.guardGate();
        st1.attack("target #1");
        st1.takeDamage(10);
        st1.beRepaired(20);
    }
    {
        std::cout << DEEPSKYBLUE <<  "Deletion when it is a pointer to ClapTrap" << RESET << std::endl;
        ClapTrap* ct = new ScavTrap ("st2");
        ct->attack("a target");
        delete ct;
    }
    return 0;
}
