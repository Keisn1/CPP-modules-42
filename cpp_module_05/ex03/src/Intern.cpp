#include "Intern.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return *this; }

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int form = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == forms[i])
            form = i;
    }

    switch (form) {
    case ShrubberyCreation:
        std::cout << "Intern creates " << forms[form] << std::endl;
        return new ShrubberyCreationForm(target);
    case RobotomyRequest:
        std::cout << "Intern creates " << forms[form] << std::endl;
        return new RobotomyRequestForm(target);
    case PresidentialPardon:
        std::cout << "Intern creates " << forms[form] << std::endl;
        return new PresidentialPardonForm(target);
    default:
        std::cerr << "This Form is unknown to the intern" << std::endl;
        return NULL;
    }
}
