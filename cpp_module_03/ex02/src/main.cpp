#include "FragTrap.h"
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
        FragTrap ft1;
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test string constructor" << RESET << std::endl;
        FragTrap ft1 ("ft1");
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy constructor" << RESET << std::endl;
        FragTrap ft1 ("ft1");
        FragTrap ft2 (ft1);
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy assignment constructor" << RESET << std::endl;
        FragTrap ft1 ("ft1");
        FragTrap ft2 ("ft2");
        ft2 = ft1;
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test other member functions" << RESET << std::endl;
        FragTrap ft1 ("ft1");
        ft1.highFivesGuys();
        ft1.attack("target #1");
        ft1.takeDamage(10);
        ft1.beRepaired(20);
    }
    {
        std::cout << DEEPSKYBLUE <<  "Deletion when it is a pointer to ClapTrap" << RESET << std::endl;
        ClapTrap* ct = new FragTrap ("ft2");
        ct->attack("a target");
        delete ct;
    }
    return 0;
}
