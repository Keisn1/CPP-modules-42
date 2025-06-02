#ifndef AFORM_H
#define AFORM_H

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeSign;
    const unsigned int _gradeExec;

  public:
    AForm(void);
    AForm(std::string, unsigned int, unsigned int);
    virtual ~AForm();
    AForm(const AForm&);
    std::string getName() const;
    bool isSigned() const;
    unsigned int getGradeSign() const;
    unsigned int getGradeExec() const;
    void beSigned(const Bureaucrat&);
    void checkExecGrade(unsigned int grade) const;
    void checkIsSigned() const;
    virtual void execute(const Bureaucrat&) const = 0;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif // AFORM_H
