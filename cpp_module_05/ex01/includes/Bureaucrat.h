#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Form.h"
#include <exception>
#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat(void);
    Bureaucrat(std::string, unsigned int);
    ~Bureaucrat(void);
    Bureaucrat(const Bureaucrat&);
    Bureaucrat& operator=(const Bureaucrat&);
    const std::string getName() const;
    unsigned int getGrade() const;
    void increment();
    void decrement();
    void signForm(Form&);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // BUREAUCRAT_H
