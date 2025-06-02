#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) {
    std::srand(std::time(NULL)); // use current time as seed for random generator
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

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
        std::cout << "===Let Miraculix pardon Jack Sparrow===" << std::endl;
        std::cout << "===(with pointers)===" << std::endl;
        Bureaucrat* b = new Bureaucrat("Miraculix", 5);
        RobotomyRequestForm pbf("Captain Jack Sparrow");
        // sign the form before executing
        b->signForm(pbf);

        // execute the form
        pbf.execute(*b);
        delete b;
    }
    // std::cout << std::endl;
    // {
    //     std::cout << "===" << "Let Miraculix pardon Jack Sparrow" << "===" << std::endl;
    //     std::cout << "===(Copy Constructor of RobotomyRequestForm)===" << std::endl;
    //     Bureaucrat* b = new Bureaucrat("Miraculix", 5);
    //     RobotomyRequestForm* pbf1 = new RobotomyRequestForm("Captain Jack Sparrow");
    //     RobotomyRequestForm pbf2 = *pbf1;
    //     // sign the form before executing
    //     b->signForm(pbf2);

    //     // execute the form
    //     pbf2.execute(*b);
    //     delete b;
    //     delete pbf1;
    // }
    // std::cout << std::endl;
    // {
    //     std::cout << "===" << "Let Miraculix pardon Jack Sparrow" << "===" << std::endl;
    //     std::cout << "===(Copy Assign Operator of RobotomyRequestForm)===" << std::endl;
    //     std::cout << "===(Failing because signing doesn't get copied with copy assign)===" << std::endl;
    //     Bureaucrat* b = new Bureaucrat("Miraculix", 5);
    //     RobotomyRequestForm* pbf1 = new RobotomyRequestForm("Captain Jack Sparrow");
    //     RobotomyRequestForm* pbf2 = new RobotomyRequestForm("Bibi Blocksberg");
    //     // sign the form before executing
    //     b->signForm(*pbf2);

    //     *pbf1 = *pbf2;

    //     // NOTE: pbf1 is still not signed, since pbf1 _signed is private and is not copied
    //     // NOTE: pbf1 has also still the same target since it is constant
    //     // execute the form
    //     try {
    //         pbf1->execute(*b);
    //     } catch (std::exception& e) {
    //         std::cout << e.what() << std::endl;
    //     }
    //     pbf2->execute(*b);
    //     delete b;
    //     delete pbf1;
    //     delete pbf2;
    // }
    // std::cout << std::endl;
    // {
    //     std::cout << "===" << "Nobody has signed the pardon for Bibi" << "===" << std::endl;
    //     Bureaucrat b("Miraculix", 5);
    //     RobotomyRequestForm pbf("Bibi Blocksberg");

    //     try {
    //         std::cout << "===" << "Execute Bibis Pardon" << "===" << std::endl;
    //         pbf.execute(b);
    //     } catch (AForm::FormNotSignedException& e) {
    //         std::cout << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // {
    //     // NOTE: 6 is too low of a grade, therefore it fails
    //     std::cout << "===" << "Rastafarix Grade is not high enough for execution" << "===" << std::endl;
    //     Bureaucrat b("Rastafarix", 6);
    //     RobotomyRequestForm pbf("Bibi Blocksberg");

    //     // sign the form before executing
    //     b.signForm(pbf);

    //     // execute form with unsufficient grade
    //     try {
    //         pbf.execute(b);
    //     } catch (AForm::GradeTooLowException& e) {
    //         std::cout << e.what() << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // {
    //     std::cout << "===" << "Rastafarix signs and executes Presidential Pardon for Bibi (habibi)"
    //               << "===" << std::endl;
    //     Bureaucrat b("Rastafarix", 5);
    //     RobotomyRequestForm pbf("Bibi Blocksberg");
    //     // sign the form before executing
    //     b.signForm(pbf);

    //     // execute the form
    //     b.executeForm(pbf);
    // }
}
