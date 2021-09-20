#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous") { _grade = 150; }

Bureaucrat::Bureaucrat(int grade) : _name("Anonymous") {
  if (grade < 1 || grade > 150)
    grade < 1 ? throw GradeTooHighException(grade)
              : throw GradeTooLowException(grade);
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name) {
    _grade = 150;
}

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
  else
    _grade--;
}

void Bureaucrat::decreaseGrade() {
  if (_grade + 1 < 1)
    throw GradeTooLowException(_grade + 1);
  else
    _grade++;
}

std::ostream &operator<<(std::ostream &c, const Bureaucrat &other) {
  c << "<" << other.getName() << ">, bureaucrat grade " << other.getGrade();
  return c;
}
