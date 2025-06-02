#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string);
    PresidentialPardonForm(PresidentialPardonForm& pbf);
    PresidentialPardonForm& operator=(PresidentialPardonForm& pbf);
    virtual ~PresidentialPardonForm(void);
    virtual void execute(const Bureaucrat&);
};

#endif // PRESIDENTIALPARDONFORM_H
