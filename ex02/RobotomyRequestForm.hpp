#ifndef _ROBOTOMY_REQUEST_FORM_H__
#define _ROBOTOMY_REQUEST_FORM_H__

#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
  std::string const _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string const &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  std::string const &getTarget(void) const;

  virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &f);

#endif