#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : Form(72, 45), _target("Anonymous") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : Form(72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(72, 45), _target(other.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  return *this;
}

std::string const &RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::cout << "drrrrrrrrrrrrrrrrrrrrr\n";
  std::srand(333);

  if (std::rand() % 2)
    std::cout << "<" + _target + " has been robotomized successfully\n";
  else
    std::cout << "<" + _target + " Failed...\n";
}
