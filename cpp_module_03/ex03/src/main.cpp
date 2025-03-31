#include "DiamondTrap.h"

int main() {
    {
        DiamondTrap d1 ("d1");
        d1.attack("target asdf");
        d1.whoAmI();
        d1.highFivesGuys();
    }
    return 0;
}
