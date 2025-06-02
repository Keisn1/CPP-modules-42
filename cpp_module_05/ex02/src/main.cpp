#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main() {
    {
        std::cout << "===Throw an exception sign Grade too high===" << std::endl;
        try {
            AForm("Noform", 0, 1);
        } catch (AForm::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception exec Grade too high===" << std::endl;
        try {
            AForm("Noform", 1, 0);
        } catch (AForm::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception sign Grade too low===" << std::endl;
        try {
            AForm("Noform", 151, 1);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception exec Grade too low===" << std::endl;
        try {
            AForm("Noform", 1, 151);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        AForm f("Noform", 1, 2);
        std::cout << f << std::endl;
        std::cout << std::endl;
    }
    {
        Bureaucrat b("Stromberg", 3);
        AForm f("kuendigung", 2, 1);
        std::cout << "===Throw an exception exec Grade too low===" << std::endl;
        try {
            f.beSigned(b);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Not possible because grade too low===" << std::endl;
        Bureaucrat b("Stromberg", 3);
        AForm f("kuendigung", 2, 1);
        b.signForm(f);
        std::cout << std::endl;
    }
    {
        std::cout << "===Successfull signing===" << std::endl;
        Bureaucrat b("Stromberg", 1);
        AForm f("kuendigung", 2, 1);
        b.signForm(f);
        std::cout << std::endl;
    }
    return 0;
}
