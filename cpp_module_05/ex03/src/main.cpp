#include "AForm.h"
#include "Intern.h"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    // robotomyRequest_main();
    rrf->isSigned();

    return 0;
}
