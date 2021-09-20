#ifndef _PRESIDENTIAL_PARDON_FORM_H__
#define _PRESIDENTIAL_PARDON_FORM_H__

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
  std::string const _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  std::string const &getTarget(void) const;

  virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &f);

#endif