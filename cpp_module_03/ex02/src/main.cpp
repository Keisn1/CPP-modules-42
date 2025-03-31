#include "ScavTrap.h"
#include "FragTrap.h"

int main() {
    {
        ScavTrap st1;
        ScavTrap st2 ("st2");
        ScavTrap st3 (st2);
        st3.set_name("st3");

        ScavTrap st4 ("st4");
        ScavTrap st5 ("st5");
        st4 = st5;
        st4.guardGate();
        st4.attack("target #1");
        st4.takeDamage(10);
        st4.beRepaired(20);
        st4.set_name("st4");
    }
    {
        FragTrap ft1;
        FragTrap ft2 ("ft2");
        FragTrap ft3 (ft2);
        ft3.set_name("ft3");

        FragTrap ft4 ("ft4");
        FragTrap ft5 ("ft5");
        ft4 = ft5;
        ft4.highFivesGuys();
        ft4.attack("target #1");
        ft4.takeDamage(10);
        ft4.beRepaired(20);
        ft4.set_name("ft4");
    }
    return 0;
}
