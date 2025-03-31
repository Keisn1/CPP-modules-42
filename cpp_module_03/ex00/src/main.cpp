#include "ClapTrap.h"

int main() {
    {
        ClapTrap ct ;
        ClapTrap ct1 ("ct1");
        ClapTrap ct2 ("ct2");
        ClapTrap ct22 (ct2);
        ct22.attack("a target");
        ct22 = ct1;

        ct22.attack("a target");
        ct22.beRepaired(20);
        ct22.takeDamage(20);
    }
    {
        ClapTrap ct1 ("ct1");
        ct1.takeDamage(5);
        ct1.takeDamage(5);
        ct1.beRepaired(5);
        ct1.takeDamage(3);
    }
    return 0;
}
