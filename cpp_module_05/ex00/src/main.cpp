#include "Bureaucrat.h"
#include <iostream>

int main() {
    {
        std::cout << "===Throw an exception for a grade that is too high===" << std::endl;
        try {
            Bureaucrat("Nobody", 0);
        } catch (Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception for a grade that is too high===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 0);
            delete b;
        } catch (Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception for a grade that is too low===" << std::endl;
        try {
            Bureaucrat("Nobody", 200);
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception for a grade that is too low (pointer)===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 200);
            delete b;
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===No exception===" << std::endl;
        Bureaucrat b("Nobody", 1);
        std::cout << std::endl;
    }
    {
        std::cout << "===No exception (pointer)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Nobody", 1);
        delete b;
        std::cout << std::endl;
    }

    {
        std::cout << "===Throw an exception increment===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 1);
            b->increment();
            delete b;
        } catch (Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "===Throw an exception decrement===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 150);
            b->decrement();
            delete b;
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        Bureaucrat b("Nobody", 1);
        std::cout << b << std::endl;
    }
    return 0;
}
