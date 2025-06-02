#include "PresidentialPardonForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf), _target(ppf._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&) { return *this; }

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    AForm::execute(b);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void presidentialPardon_main() {
    {
        std::cout << "===" << "Let Miraculix pardon Jack Sparrow" << "===" << std::endl;
        Bureaucrat b("Miraculix", 5);
        PresidentialPardonForm pbf("Captain Jack Sparrow");
        // sign the form before executing
        b.signForm(pbf);

        // execute the form
        pbf.execute(b);
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Miraculix pardon Jack Sparrow===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        PresidentialPardonForm pbf("Captain Jack Sparrow");
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        pbf.execute(*b);
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===" << "Let Miraculix pardon Jack Sparrow" << "===" << std::endl;
        std::cout << "===(Copy Constructor of PresidentialPardonForm)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        PresidentialPardonForm* pbf1 = new PresidentialPardonForm("Captain Jack Sparrow");
        PresidentialPardonForm pbf2 = *pbf1;
        // sign the form before executing
        b->signForm(pbf2);

        // execute the form
        pbf2.execute(*b);
        delete b;
        delete pbf1;
    }
    std::cout << std::endl;
    {
        std::cout << "===" << "Let Miraculix pardon Jack Sparrow" << "===" << std::endl;
        std::cout << "===(Copy Assign Operator of PresidentialPardonForm)===" << std::endl;
        std::cout << "===(Failing because signing doesn't get copied with copy assign)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        PresidentialPardonForm* pbf1 = new PresidentialPardonForm("Captain Jack Sparrow");
        PresidentialPardonForm* pbf2 = new PresidentialPardonForm("Bibi Blocksberg");
        // sign the form before executing
        b->signForm(*pbf2);

        *pbf1 = *pbf2;

        // NOTE: pbf1 is still not signed, since pbf1 _signed is private and is not copied
        // NOTE: pbf1 has also still the same target since it is constant
        // execute the form
        try {
            pbf1->execute(*b);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        pbf2->execute(*b);
        delete b;
        delete pbf1;
        delete pbf2;
    }
    std::cout << std::endl;
    {
        std::cout << "===" << "Nobody has signed the pardon for Bibi" << "===" << std::endl;
        Bureaucrat b("Miraculix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");

        try {
            std::cout << "===" << "Execute Bibis Pardon" << "===" << std::endl;
            pbf.execute(b);
        } catch (AForm::FormNotSignedException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        // NOTE: 6 is too low of a grade, therefore it fails
        std::cout << "===" << "Rastafarix Grade is not high enough for execution" << "===" << std::endl;
        Bureaucrat b("Rastafarix", 6);
        PresidentialPardonForm pbf("Bibi Blocksberg");

        // sign the form before executing
        b.signForm(pbf);

        // execute form with unsufficient grade
        try {
            pbf.execute(b);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===" << "Rastafarix signs and executes Presidential Pardon for Bibi (habibi)"
                  << "===" << std::endl;
        Bureaucrat b("Rastafarix", 5);
        PresidentialPardonForm pbf("Bibi Blocksberg");
        // sign the form before executing
        b.signForm(pbf);

        // execute the form
        b.executeForm(pbf);
    }
}
