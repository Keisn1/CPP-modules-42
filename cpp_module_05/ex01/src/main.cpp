#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main() {
    {
        std::cout << "===Throw an exception sign Grade too high===" << std::endl;
        try {
            Form("Noform", 0, 1);
        } catch (Form::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception exec Grade too high===" << std::endl;
        try {
            Form("Noform", 1, 0);
        } catch (Form::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception sign Grade too low===" << std::endl;
        try {
            Form("Noform", 151, 1);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception exec Grade too low===" << std::endl;
        try {
            Form("Noform", 1, 151);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        Form f("Noform", 1, 2);
        std::cout << f << std::endl;
        std::cout << std::endl;
    }
    {
        Bureaucrat b("Stromberg", 3);
        Form f("kuendigung", 2, 1);
        std::cout << "===Throw an exception exec Grade too low===" << std::endl;
        try {
            f.beSigned(b);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Not possible because grade too low===" << std::endl;
        Bureaucrat b("Stromberg", 3);
        Form f("kuendigung", 2, 1);
        b.signForm(f);
        std::cout << std::endl;
    }
    {
        std::cout << "===Successfull signing===" << std::endl;
        Bureaucrat b("Stromberg", 1);
        Form f("kuendigung", 2, 1);
        b.signForm(f);
        if (f.isSigned()) {
            std::cout << f << ", was signed" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
