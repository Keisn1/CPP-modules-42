#ifndef FORM_H
#define FORM_H

#include <exception>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeSign;
    const unsigned int _gradeExec;

  public:
    Form(void);
    Form(std::string, unsigned int, unsigned int);
    ~Form(void);
    Form(const Form&);
    Form& operator=(const Form&);

    std::string getName() const;
    bool isSigned() const;
    unsigned int getGradeSign() const;
    unsigned int getGradeExec() const;
    void beSigned(const Bureaucrat&);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_H
