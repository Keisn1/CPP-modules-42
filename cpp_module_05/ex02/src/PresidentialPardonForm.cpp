#include "PresidentialPardonForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string n) : AForm(n, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(const Bureaucrat& b) {
    try {
        checkIsSigned();
        checkExecGrade(b.getGrade());
    } catch (std::exception& e) {
        std::cout << "Could not exec Presidential Pardon due to " << e.what() << std::endl;
        return;
    }

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
