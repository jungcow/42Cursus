#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : Form("robotomy request", 72, 45), _target("Anonymous") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : Form("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form("robotomy request", 72, 45), _target(other.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  (void)other;
  return *this;
}

std::string const &RobotomyRequestForm::getTarget() const { return (_target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::cout << "drrrrrrrrrrrrrrrrrrrrr\n";
  std::srand(time(0));

  if (std::rand() % 2)
    std::cout << "<" + _target + "> has been robotomized successfully ----- ";
  else {
    throw NoExecException("<" + _target + "> Failed...");
  }
}

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &f) {
  c << "[ Form ]\n\"Name\": " << f.getName()
    << "\n\"Target\": " << f.getTarget()
    << "\n\"Status\": " << f.getSignedFlag()
    << "\n\"Sign_Grade\": " << f.getSignedGrade()
    << "\n\"Exec_Grade\": " << f.getExecGrade() << '\n';
  return c;
}
