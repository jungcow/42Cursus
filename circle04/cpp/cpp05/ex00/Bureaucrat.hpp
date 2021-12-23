#ifndef _BUREAUCRAT_H__
#define _BUREAUCRAT_H__

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  std::string const _name;
  int               _grade;

  class GradeTooHighException : public std::exception {
  private:
    int _g;

  public:
    GradeTooHighException(int g);
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  private:
    int _g;

  public:
    GradeTooLowException(int g);
    virtual const char *what() const throw();
  };

public:
  Bureaucrat();
  Bureaucrat(int grade);
  Bureaucrat(std::string const &name);
  Bureaucrat(std::string const &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &other);

  std::string const &getName(void) const;
  int                getGrade(void) const;
  void               setGrade(int grade);

  void increaseGrade(void);
  void decreaseGrade(void);
};

std::ostream &operator<<(std::ostream &c, const Bureaucrat &other);

#endif
