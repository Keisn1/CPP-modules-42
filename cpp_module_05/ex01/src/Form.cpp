#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

Form::Form(void) : _name(""), _signed(false), _gradeSign(1), _gradeExec(1) {}

Form::Form(std::string n, unsigned int gs, unsigned int ge) : _name(n), _signed(false), _gradeSign(gs), _gradeExec(ge) {

    if (gs < 1)
        throw Form::GradeTooHighException();
    if (gs > 150)
        throw Form::GradeTooLowException();

    if (ge < 1)
        throw Form::GradeTooHighException();
    if (ge > 150)
        throw Form::GradeTooLowException();
}

Form::~Form(void) {}

std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
unsigned int Form::getGradeSign() const { return _gradeSign; }
unsigned int Form::getGradeExec() const { return _gradeExec; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", Form sign grade: " << f.getGradeSign() << " , exec grade: " << f.getGradeExec();
    return os;
}

const char* Form::GradeTooHighException::what() const throw() { return "Exception: Grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Exception: Grade too low"; }
