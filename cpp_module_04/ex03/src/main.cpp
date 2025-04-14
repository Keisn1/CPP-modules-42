#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
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
    {
        std::cout << DEEPSKYBLUE << "Second test: Cure and CureClone" << RESET << std::endl;
        Character target; // default name "nobody"

        // Create a Cure materia and clone it
        Cure* cure = new Cure();
        AMateria* cureClone = cure->clone();

        // Use both the original and the clone on the target Character
        cure->use(target);
        cureClone->use(target);

        // Clean up
        delete cure;
        delete cureClone;
    }
    {
        std::cout << DEEPSKYBLUE << "Third test: Character equip, unequip, and use" << RESET << std::endl;
        Character character1; // default name "nobody"
        Character character2("Player2");

        Ice* ice = new Ice();
        Cure* cure = new Cure();

        character1.equip(ice);
        character1.equip(cure);

        // Use the equipped materials
        character1.use(0, character2); // should use ice on character2
        character1.use(1, character2); // should use cure on character2

        // Unequip the ice and use again
        AMateria* del = character1.getMateria(0);
        character1.unequip(0);
        delete del;

        character1.use(0, character2); // should do nothing
    }
    {
        std::cout << DEEPSKYBLUE << "Fourth test: MateriaSource learn and create" << RESET << std::endl;
        MateriaSource materiaSource;

        // Create some materia and teach them to the source
        AMateria* ice = new Ice();
        AMateria* cure = new Cure();

        materiaSource.learnMateria(ice);
        materiaSource.learnMateria(cure);

        // Try creating materia from what was learned
        AMateria* createdIce = materiaSource.createMateria("ice");
        AMateria* createdCure = materiaSource.createMateria("cure");

        // Test the creation is correct by using the new materia on a character
        Character target("TestTarget");
        if (createdIce) {
            createdIce->use(target);
        }
        if (createdCure) {
            createdCure->use(target);
        }

        // Release dynamically allocated resources
        delete createdIce;
        delete createdCure;
        // No need to delete ice and cure since MateriaSource takes ownership
    }
    {
        std::cout << DEEPSKYBLUE << "Fifth test: Equipment limits and Unequip edge case" << RESET << std::endl;
        Character character("MaxEquipTester");

        // Create materia
        AMateria* ice1 = new Ice();
        AMateria* ice2 = new Ice();
        AMateria* ice3 = new Ice();
        AMateria* ice4 = new Ice();
        AMateria* excessIce = new Ice();

        // Equip the maximum number of materia
        character.equip(ice1);
        character.equip(ice2);
        character.equip(ice3);
        character.equip(ice4);

        // Try to equip an extra materia (should do nothing)
        character.equip(excessIce);

        // Use the equipped materia
        Character target("Target");
        for (int i = 0; i < MAX_NBR_MATERIA; ++i) {
            character.use(i, target);
        }

        // Successfully unequip a materia
        AMateria* del = character.getMateria(0);
        character.unequip(0);
        if (del)
            delete del;

        // Attempt to unequip from an empty or invalid slot (should do nothing)
        del = character.getMateria(0);
        character.unequip(0);
        if (del)
            delete del;

        del = character.getMateria(1);
        character.unequip(1);
        if (del)
            delete del;

        del = character.getMateria(2);
        character.unequip(2);
        if (del)
            delete del;

        del = character.getMateria(3);
        character.unequip(3);
        if (del)
            delete del;

        character.unequip(4);
        character.unequip(-1);

        // Clean up dynamically allocated resources
        delete excessIce;
    }
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }

    return 0;
}
