#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <unistd.h>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default Target") {}

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

void shrubbery_main() {
    {
        std::cout << "===" << "Ash signs Shrubbery, Pikachu file" << "===" << std::endl;
        Bureaucrat b("Ash", 5);
        ShrubberyCreationForm scf("Pikachu");

        // sign the form before executing
        b.signForm(scf);

        // execute the form
        scf.execute(b);
    }
    std::cout << std::endl;
    {
        std::cout << "===" << "Lilly signs Shrubbery, Glumanda file" << "===" << std::endl;
        Bureaucrat b("Lilly", 5);
        ShrubberyCreationForm scf("Glumanda");

        // sign the form before executing
        b.signForm(scf);

        // execute the form
        b.executeForm(scf);
    }
    std::cout << std::endl;
    {
        std::cout << "===Rocko signs Shrubbery, Bisasam file===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Rokko", 55);
        ShrubberyCreationForm pbf("Bisasam");
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        b->executeForm(pbf);
        delete b;
    }
}
