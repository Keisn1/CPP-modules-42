#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

class RobotomyRequestForm : public AForm {
  private:
    const std::string _target;

  public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string);
    RobotomyRequestForm(const RobotomyRequestForm& pbf);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& pbf);
    virtual ~RobotomyRequestForm(void);
    virtual void execute(const Bureaucrat&) const;
};

void robotomyRequest_main();

#endif // ROBOTOMYREQUESTFORM_H
