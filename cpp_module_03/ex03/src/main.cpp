#include "DiamondTrap.h"
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
        DiamondTrap d1;
        d1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test string constructor" << RESET << std::endl;
        DiamondTrap d1 ("d1");
        d1.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test copy constructor" << RESET << std::endl;
        DiamondTrap d1 ("d1");
        DiamondTrap d2 (d1);
        d2.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test assignment operator" << RESET << std::endl;
        DiamondTrap d1 ("d1");
        DiamondTrap d2 ("d2");
        d2 = d1;
        d2.printAttributes();
    }
    {
        std::cout << DEEPSKYBLUE <<  "Test methods" << RESET << std::endl;
        DiamondTrap d1 ("d1");
        d1.attack("target asdf");
        d1.whoAmI();
        d1.highFivesGuys();
    }
    return 0;
}
