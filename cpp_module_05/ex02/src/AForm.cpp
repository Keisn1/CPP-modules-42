#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

AForm::AForm(void) : _name(""), _signed(false), _gradeSign(1), _gradeExec(1) {}

AForm::AForm(std::string n, unsigned int gs, unsigned int ge)
    : _name(n), _signed(false), _gradeSign(gs), _gradeExec(ge) {

    if (gs < 1)
        throw AForm::GradeTooHighException();
    if (gs > 150)
        throw AForm::GradeTooLowException();

    if (ge < 1)
        throw AForm::GradeTooHighException();
    if (ge > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm(void) {}

AForm::AForm(const AForm& f) : _name(f._name), _signed(f._signed), _gradeSign(f._gradeSign), _gradeExec(f._gradeExec) {}

std::string AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
unsigned int AForm::getGradeSign() const { return _gradeSign; }
unsigned int AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign) {
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", Form sign grade: " << f.getGradeSign() << " , exec grade: " << f.getGradeExec();
    return os;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Exception: Grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Exception: Grade too low"; }

const char* AForm::FormNotSignedException::what() const throw() { return "Exception: Form was not signed"; }

void AForm::checkExecGrade(unsigned int grade) const {
    if (grade > _gradeExec)
        throw GradeTooLowException();
}

void AForm::checkIsSigned() const {
    if (!_signed)
        throw FormNotSignedException();
}
