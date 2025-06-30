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

void robotomyRequest_main() {
    {
        std::cout << "===" << "Pikachu is getting robotomized by Ash" << "===" << std::endl;
        Bureaucrat b("Ash", 5);
        RobotomyRequestForm pbf("Pikachu");

        // sign the form before executing
        b.signForm(pbf);

        // execute the form
        pbf.execute(b);
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Lilly robotomize Glumanda===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Lilly", 5);
        RobotomyRequestForm pbf("Glumanda");
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        pbf.execute(*b);
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Default Robotomizer robotomize - Form without Target===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Default Robotomizer", 5);
        RobotomyRequestForm pbf;
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        pbf.execute(*b);
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let  robotomize exception===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat;
        RobotomyRequestForm pbf;
        // sign the form before executing
        try {
            b->signForm(pbf);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << "could not sign: " << e.what() << std::endl;
        }
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Lilly robotomize===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Lilly", 55);
        RobotomyRequestForm pbf;
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        try {
            pbf.execute(*b);
        } catch (AForm::GradeTooLowException& e) {
            std::cout << "could not execute: " << e.what() << std::endl;
        }

        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Lilly robotomize Glumanda===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Lilly", 5);
        RobotomyRequestForm pbf("Glumanda");
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        b->executeForm(pbf);
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Lilly robotomize but Grade too low===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Lilly", 55);
        RobotomyRequestForm pbf;
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        b->executeForm(pbf);
        delete b;
    }
    std::cout << std::endl;
    {
        std::cout << "===Let Lilly robotomize but Lilly could not sign===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Lilly", 100);
        RobotomyRequestForm pbf;
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        b->executeForm(pbf);
        delete b;
    }
}
