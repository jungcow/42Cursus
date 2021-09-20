#ifndef _INTERN_H__
#define _INTERN_H__

#include "Form.hpp"
#include <iostream>

class Intern;

typedef Form *(Intern::*FUNCPTR)(std::string const &);

class Intern {
private:
  static const std::string _formArray[3];
  static FUNCPTR           _fptrArray[3];

  Form *createShrubberyForm(std::string const &target);
  Form *createRobotomyForm(std::string const &target);
  Form *createPresidentialForm(std::string const &target);

  class InternException : public std::exception {
  private:
    std::string const _message;

  public:
    InternException();
    InternException(std::string const &message);
    virtual ~InternException() throw();
    virtual const char *what() const throw();
  };

public:
  Intern();
  Intern(const Intern &other);
  ~Intern();
  Intern &operator=(const Intern &other);

  Form *makeForm(std::string const &formType, std::string const &target);
};

#endif