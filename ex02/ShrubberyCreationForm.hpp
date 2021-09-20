#ifndef _SHRUBBERYY_CREATION_FORM_H__
#define _SHRUBBERYY_CREATION_FORM_H__

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
private:
  std::string const _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  std::string const &getTarget(void) const;

  virtual void execute(Bureaucrat const &executor) const;
};

#endif