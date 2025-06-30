#include "PresidentialPardonForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5), _target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf) : AForm(ppf), _target(ppf._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&) { return *this; }

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    AForm::execute(b);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
