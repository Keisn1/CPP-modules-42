#include "AMateria.h"
#include "Character.h"
#include "Ice.h"
#include <iostream>

#define DEEPSKYBLUE "\033[38;2;0;191;255m"
#define RESET "\033[0m"

int main() {
    {
        std::cout << DEEPSKYBLUE << "First test: Ice and IceClone" << RESET << std::endl;
        Character target;
        // Create an Ice materia and clone it
        Ice* ice = new Ice();
        AMateria* iceClone = ice->clone();

        // Use both the original and the clone on the target Character
        ice->use(target);
        iceClone->use(target);

        // Clean up
        delete ice;
        delete iceClone;
    }
    return 0;
}
