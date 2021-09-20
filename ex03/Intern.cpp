#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// typedef Form *(Intern::*FUNCPTR)(std::string const &);

const std::string Intern::_formArray[3] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

FUNCPTR Intern::_fptrArray[3] = {&Intern::createShrubberyForm,
                                 &Intern::createRobotomyForm,
                                 &Intern::createPresidentialForm};

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Form *Intern::createShrubberyForm(std::string const &target) {
  return new ShrubberyCreationForm(target);
}
Form *Intern::createRobotomyForm(std::string const &target) {
  return new RobotomyRequestForm(target);
}
Form *Intern::createPresidentialForm(std::string const &target) {
  return new PresidentialPardonForm(target);
}

Intern::InternException::InternException() : _message("There's No Type") {}
Intern::InternException::InternException(std::string const &message)
    : _message(message) {}
Intern::InternException::~InternException() throw() {}

const char *Intern::InternException::what() const throw() {
  return _message.c_str();
}

Form *Intern::makeForm(std::string const &formType, std::string const &target) {
  std::string tmp = formType;

  int i = 0;
  while (tmp[i]) {
    if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
      tmp[i] += ('a' - 'A');
    }
    i++;
  }
  try {
    for (int i = 0; i < 3; i++) {
      if (_formArray[i] == tmp) {
        std::cout << "Intern creates <" + _formArray[i] + ">\n";
        return (this->*_fptrArray[i])(target);
      }
    }
    throw InternException();
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return NULL;
}