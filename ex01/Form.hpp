#ifndef _FORM_H__
#define _FORM_H__

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
  std::string const _name;
  bool              _signed;
  int const         _signedGrade;
  int const         _execGrade;

  class GradeTooHighException : public std::exception {
  private:
    std::string const _message;

  public:
    GradeTooHighException();
    GradeTooHighException(std::string const &message);
    ~GradeTooHighException() throw();
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string const _message;

  public:
    GradeTooLowException();
    GradeTooLowException(std::string const &message);
    ~GradeTooLowException() throw();
    virtual const char *what() const throw();
  };

public:
  Form();
  Form(std::string const &name);
  Form(int signedGrade, int execGrade);
  Form(std::string const &name, int signedGrade, int execGrade);
  Form(const Form &other);
  ~Form();
  Form &operator=(const Form &other);

  std::string const &getName(void) const;
  int                getSignedGrade(void) const;
  int                getExecGrade(void) const;
  bool               getSignedFlag(void) const;
  void               setSignedFlag(bool flag);

  void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &c, const Form &f);

#endif
