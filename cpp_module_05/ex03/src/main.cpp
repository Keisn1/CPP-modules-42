
#include "Bureaucrat.h"
#include "Intern.h"
#include <iostream>

int main() {
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        rrf->isSigned();
        delete rrf;
    }
    std::cout << std::endl;
    {
        Bureaucrat b("theBureaucrat", 40);
        Intern* someRandomIntern = new Intern();
        AForm* rrf;
        rrf = someRandomIntern->makeForm("robotomy request", "Bender");
        b.signForm(*rrf);
        rrf->execute(b);

        delete someRandomIntern;
        delete rrf;
    }
    std::cout << std::endl;
    {
        Bureaucrat b("theBureaucrat", 140);
        Intern* someRandomIntern = new Intern();
        AForm* rrf;
        rrf = someRandomIntern->makeForm("robotomy request", "Bender");
        b.signForm(*rrf);

        try {
            rrf->execute(b);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        delete someRandomIntern;
        delete rrf;
    }
    std::cout << std::endl;
    {
        Bureaucrat b("theBureaucrat", 140);
        Intern* someRandomIntern = new Intern();
        AForm* rrf;
        rrf = someRandomIntern->makeForm("robotomy request", "Bender");
        b.signForm(*rrf);
        b.executeForm(*rrf);

        delete someRandomIntern;
        delete rrf;
    }
    std::cout << std::endl;
    {
        Bureaucrat b("theBureaucrat", 60);
        Intern* someRandomIntern = new Intern();
        AForm* rrf;
        rrf = someRandomIntern->makeForm("robotomy request", "Bender");
        b.signForm(*rrf);
        b.executeForm(*rrf);

        delete someRandomIntern;
        delete rrf;
    }

    return 0;
}
