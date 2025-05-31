#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <istream>
#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    unsigned int _grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string, unsigned int);
    ~Bureaucrat(void);
    Bureaucrat(const Bureaucrat&);
    Bureaucrat operator=(const Bureaucrat&);
    const std::string getName() const;
    unsigned int getGrade() const;
    void increment();
    void decrement();
    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif // BUREAUCRAT_H
