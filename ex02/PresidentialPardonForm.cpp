#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : Form(145, 137), _target("Anonymous") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : Form(145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(145, 137), _target(other.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  return *this;
}

std::string const &RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::cout << _target + " has been pardoned by Zafod Beeblebrox.";
}
