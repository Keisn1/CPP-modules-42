#include "AForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

int main() {
    {
        std::cout << "===Throw an exception sign Grade too high===" << std::endl;
        try {
            PresidentialPardonForm pbf("Captain Jack Sparrow");
        } catch (AForm::GradeTooHighException& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
