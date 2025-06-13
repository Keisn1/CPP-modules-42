#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <string>

class ShrubberyCreationForm : public AForm {
  private:
    const std::string _target;

  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string);
    ShrubberyCreationForm(const ShrubberyCreationForm& pbf);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& pbf);
    virtual ~ShrubberyCreationForm(void);
    virtual void execute(const Bureaucrat&) const;
};

#endif // SHRUBBERYCREATIONFORM_H
