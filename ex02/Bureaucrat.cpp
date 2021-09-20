#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous") { _grade = 150; }

Bureaucrat::Bureaucrat(int grade) : _name("Anonymous") {
  if (grade < 1 || grade > 150)
    grade < 1 ? throw GradeTooHighException(grade)
              : throw GradeTooLowException(grade);
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name) { _grade = 150; }

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
  if (grade < 1 || grade > 150)
    grade < 1 ? throw GradeTooHighException(grade)
              : throw GradeTooLowException(grade);
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()) {
  _grade = other.getGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  _grade = other.getGrade();
  return (*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int g) { _g = g; }
Bureaucrat::GradeTooLowException::GradeTooLowException(int g) { _g = g; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("[ Error ] Too High Grade");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("[ Error ] Too Low Grade");
}

std::string const &Bureaucrat::getName() const { return (_name); }
int                Bureaucrat::getGrade() const { return (_grade); }
void               Bureaucrat::setGrade(int grade) {
  if (grade < 1 || grade > 150)
    grade < 1 ? throw GradeTooHighException(grade)
                            : throw GradeTooLowException(grade);
  else
    _grade = grade;
}

void Bureaucrat::increaseGrade() {
  if (_grade - 1 > 150)
    throw GradeTooHighException(_grade - 1);
  int tmp = _grade--;
  std::cout << _name << "'s Grade is Increased!"
            << "[" << tmp << " to " << _grade << "]" << std::endl;
}

void Bureaucrat::decreaseGrade() {
  if (_grade + 1 < 1)
    throw GradeTooLowException(_grade + 1);
  int tmp = _grade++;
  std::cout << _name << "'s Grade is Decreased!"
            << "[" << tmp << " to " << _grade << "]" << std::endl;
}

void Bureaucrat::signForm(Form &form) const {
  try {
    form.besigned(*this);
    std::cout << "<" << _name << "> signs "
              << "<" << form.getName() << ">" << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
}

void Bureaucrat::executeForm(Form const &form) {
  try {
    form.execute(*this);
    std::cout << "<" + _name + "> executes <" + form.getName() + ">\n";
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
}

std::ostream &operator<<(std::ostream &c, const Bureaucrat &b) {
  c << "<" << b.getName() << ">, bureaucrat grade " << b.getGrade();
  return c;
}
