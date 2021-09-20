#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("Presidential", 25, 5), _target("Anonymous") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : Form(25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : Form("Presidential", 25, 5), _target(other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  (void)other;
  return *this;
}

std::string const &PresidentialPardonForm::getTarget() const {
  return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::cout << _target + " has been pardoned by Zafod Beeblebrox. ----- ";
}

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &f) {
  c << "[ Form ]\n\"Name\": " << f.getName()
    << "\n\"Target\": " << f.getTarget()
    << "\n\"Status\": " << f.getSignedFlag()
    << "\n\"Sign_Grade\": " << f.getSignedGrade()
    << "\n\"Exec_Grade\": " << f.getExecGrade() << '\n';
  return c;
}
