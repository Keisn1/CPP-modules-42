#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
  private:
    const std::string _target;

  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string);
    PresidentialPardonForm(PresidentialPardonForm& pbf);
    PresidentialPardonForm& operator=(PresidentialPardonForm& pbf);
    virtual ~PresidentialPardonForm(void);
    virtual void execute(const Bureaucrat&) const;
};

#endif // PRESIDENTIALPARDONFORM_H
