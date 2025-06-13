#include "ShrubberyCreationForm.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ppf) : AForm(ppf), _target(ppf._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&) { return *this; }

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    AForm::execute(b);

    std::ofstream file((_target + "_shrubbery").c_str(), std::ios::binary);
    if (file.bad()) {
        std::cerr << "Could not create file: " << _target << "_shrubbery" << std::endl;
        return;
    }

    file << "   /\\" << std::endl
         << "  /**\\" << std::endl
         << " /****\\" << std::endl
         << "/******\\" << std::endl
         << "  ||||" << std::endl;

    file.close();
}
