#include "AForm.h"
#include "Bureaucrat.h"
#include "Intern.h"

int main() {
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // robotomyRequest_main();
        rrf->isSigned();
    }
    {
        Bureaucrat b("theBureaucrat", 40);
        Intern* someRandomIntern = new Intern();
        AForm* rrf;
        rrf = someRandomIntern->makeForm("robotomy request", "Bender");
        // robotomyRequest_main();
        b.signForm(*rrf);
        rrf->execute(b);

        delete someRandomIntern;
        delete rrf;
    }

    return 0;
}
