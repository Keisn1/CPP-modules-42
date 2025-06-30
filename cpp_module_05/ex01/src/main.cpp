#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main() {
    {
        std::cout << "===Throw an exception signGrade too high===" << std::endl;
        try {
            Form("Noform", 0, 1);
        } catch (Form::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception execGrade too high===" << std::endl;
        try {
            Form("Noform", 1, 0);
        } catch (Form::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception signGrade too low===" << std::endl;
        try {
            Form("Noform", 151, 1);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception execGrade too low===" << std::endl;
        try {
            Form("Noform", 1, 151);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception execGrade too low===" << std::endl;
        Bureaucrat b("Stromberg", 3);
        Form f("kuendigung", 2, 1);
        try {
            f.beSigned(b);
        } catch (Form::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Not possible because grade too low===" << std::endl;
        Bureaucrat b("Stromberg", 3);
        Form f("kuendigung", 2, 1);
        b.signForm(f);
    }
    std::cout << std::endl;
    {
        std::cout << "===Successfull signing===" << std::endl;
        Bureaucrat b("Stromberg", 1);
        Form f("kuendigung", 2, 1);
        b.signForm(f);
        if (f.isSigned()) {
            std::cout << f << ", was signed" << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy a Form===" << std::endl;
        Form f("Form1", 25, 45);
        std::cout << f << std::endl;

        Form f1(f);
        std::cout << f1 << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy a Form===" << std::endl;
        Form* f = new Form("Form1", 25, 45);
        std::cout << *f << std::endl;

        Form f1(*f);
        std::cout << f1 << std::endl;
        delete f;
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy assign a Form===" << std::endl;
        Form f1("Form1", 25, 45);
        std::cout << f1 << std::endl;
        Form f2("Form2", 125, 145);
        std::cout << f2 << std::endl;

        // sign f2
        Bureaucrat b("Stromberg", 20);
        f2.beSigned(b);

        f1 = f2;
        // f1 should be signed
        if (f1.isSigned())
            std::cout << f1 << ", is signed" << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy assign a Form (with pointers)===" << std::endl;
        Form* f1 = new Form("Form1", 25, 45);
        std::cout << *f1 << std::endl;
        Form* f2 = new Form("Form2", 125, 145);
        std::cout << *f2 << std::endl;

        // sign f2
        Bureaucrat b("Stromberg", 20);
        f2->beSigned(b);

        *f1 = *f2;
        // f1 should be signed
        if (f1->isSigned())
            std::cout << *f1 << ", is signed" << std::endl;
        delete f1;
        delete f2;
    }
    std::cout << std::endl;
    {
        Form f("Noform", 1, 2);
        std::cout << f << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
