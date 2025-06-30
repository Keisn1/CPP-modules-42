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
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception for a grade that is too high(pointer)===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 0);
            delete b;
        } catch (Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception for a grade that is too low===" << std::endl;
        try {
            Bureaucrat("Nobody", 200);
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception for a grade that is too low (pointer)===" << std::endl;
        try {
            Bureaucrat* b = new Bureaucrat("Nobody", 200);
            delete b;
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "===Throw an exception increment===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Nobody", 1);
        try {
            b->increment();
        } catch (Bureaucrat::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Throw an exception decrement===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Nobody", 150);
        try {
            b->decrement();
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
        }
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy a bureaucrat===" << std::endl;
        Bureaucrat b("Bureaucrat1", 45);
        std::cout << b << std::endl;

        Bureaucrat c(b);
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy assign a bureaucrat===" << std::endl;
        Bureaucrat b("Bureaucrat1", 45);
        std::cout << b << std::endl;
        Bureaucrat c("Bureaucrat2", 50);
        std::cout << c << std::endl;

        c = b;
        std::cout << c << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "===Copy assign a bureaucrat===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Bureaucrat1", 45);
        std::cout << *b << std::endl;
        Bureaucrat* c = new Bureaucrat("Bureaucrat2", 50);
        std::cout << *c << std::endl;

        *c = *b;
        std::cout << *c << std::endl;
        delete b;
        delete c;
    }
    std::cout << std::endl;
    {
        std::cout << "===No exception===" << std::endl;
        Bureaucrat b("Nobody", 1);
    }
    std::cout << std::endl;
    {
        std::cout << "===No exception (pointer)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Nobody", 1);
        delete b;
        std::cout << std::endl;
    }
    return 0;
}
