#include "RobotomyRequestForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("Default Target") {
    std::srand(std::time(NULL)); // use current time as seed for random generator
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
    std::srand(std::time(NULL)); // use current time as seed for random generator
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf) : AForm(rrf), _target(rrf._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&) { return *this; }

void RobotomyRequestForm::execute(const Bureaucrat& b) const {
    AForm::execute(b);

    std::cout << "Robotomy Request makes drilling noises." << std::endl;

    // https://en.cppreference.com/w/cpp/numeric/random/RAND_MAX.html
    double p = static_cast< double >(std::rand()) / RAND_MAX;
    if (p >= 0.5)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "Robotomization of " << _target << " failed." << std::endl;
}
