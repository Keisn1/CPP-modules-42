#include "AForm.h"
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

    return 0;
}
