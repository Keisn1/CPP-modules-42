#include "DiamondTrap.h"

int main() {
    {
        DiamondTrap d1 ("d1");
        d1.attack("target asdf");
        d1.whoAmI();
    }
    {
        FragTrap f1("f1");
    }
    return 0;
}
