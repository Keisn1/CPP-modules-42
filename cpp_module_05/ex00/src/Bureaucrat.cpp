#include "Bureaucrat.h"
#include <iostream>

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string n, unsigned int g) : _name(n) {
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();

    _grade = g;
    std::cout << "Bureaucrat " << _name << " constructed" << std::endl;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat " << _name << " destructed" << std::endl; }

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name), _grade(b._grade) {
    std::cout << "Copy constructed: " << b << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this == &b)
        return *this;
    this->_grade = b._grade;
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Exception: Grade is too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Exception: Grade is too low"; }

const std::string Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::increment() {
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrement() {
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}
