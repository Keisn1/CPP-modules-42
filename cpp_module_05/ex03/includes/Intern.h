#ifndef INTERN_H
#define INTERN_H

#include "string"

class AForm;

class Intern {
  public:
    enum KnowForms { ShrubberyCreation, RobotomyRequest, PresidentialPardon };
    Intern(void);
    ~Intern(void);
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    AForm* makeForm(std::string formName, std::string target);
};

#endif // INTERN_H
