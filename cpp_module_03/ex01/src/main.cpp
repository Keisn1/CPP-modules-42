#include "ScavTrap.h"

int main() {
    ScavTrap st1;
    ScavTrap st2 ("st2");
    ScavTrap st3 (st2);
    st3.set_name("st3");

    ScavTrap st4 ("st4");
    ScavTrap st5 ("st5");
    st4 = st5;
    st4.guardGate();
    st4.set_name("st4");
    return 0;
}
