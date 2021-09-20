#include "Form.hpp"
#include <sstream>

Form::Form() : _name("Default"), _signedGrade(150), _execGrade(150) {
  _signed = 0;
}

Form::Form(int const signedGrade, int const execGrade)
    : _name("Default"), _signedGrade(signedGrade), _execGrade(execGrade) {
  if (signedGrade < 1 || signedGrade > 150)
    signedGrade < 1 ? throw GradeTooHighException()
                    : throw GradeTooLowException();
  if (execGrade < 1 || execGrade > 150)
    execGrade < 1 ? throw GradeTooHighException()
                  : throw GradeTooLowException();
  _signed = 0;
}

Form::Form(std::string const &name)
    : _name(name), _signedGrade(150), _execGrade(150) {
  _signed = 0;
}

Form::Form(std::string const &name, int const signedGrade, int const execGrade)
    : _name(name), _signedGrade(signedGrade), _execGrade(execGrade) {
  if (signedGrade < 1 || signedGrade > 150)
    signedGrade < 1 ? throw GradeTooHighException()
                    : throw GradeTooLowException();
  if (execGrade < 1 || execGrade > 150)
    execGrade < 1 ? throw GradeTooHighException()
                  : throw GradeTooLowException();
  _signed = 0;
}

Form::Form(const Form &other)
    : _name(other.getName()), _signedGrade(other.getSignedGrade()),
      _execGrade(other.getExecGrade()) {
  _signed = other.getSignedFlag();
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
  _signed = other.getSignedFlag();
  return *this;
}

Form::GradeTooHighException::GradeTooHighException()
    : _message("Grade is Too High!") {}
Form::GradeTooLowException::GradeTooLowException()
    : _message("Grade is Too Low") {}

Form::GradeTooHighException::GradeTooHighException(std::string const &message)
    : _message(message) {}
Form::GradeTooLowException::GradeTooLowException(std::string const &message)
    : _message(message) {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
  return _message.c_str();
}
const char *Form::GradeTooLowException::what() const throw() {
  return _message.c_str();
}

std::string const &Form::getName() const { return (_name); }
int                Form::getSignedGrade() const { return (_signedGrade); }
int                Form::getExecGrade() const { return (_execGrade); }
bool               Form::getSignedFlag() const { return (_signed); }
void               Form::setSignedFlag(bool flag) { _signed = flag; }

void Form::besigned(const Bureaucrat &b) {
  std::stringstream formGradeString, BureaucratGradeString;
  formGradeString << _signedGrade;
  BureaucratGradeString << b.getGrade();
  std::string tmp = "<" + _name + "> cannot sign <" + _name +
                    "> because Form Grade(" + formGradeString.str() +
                    ") is Higher than " + b.getName() + "(" +
                    BureaucratGradeString.str() + ")!";
  if (_signedGrade < b.getGrade()) {
    throw GradeTooLowException(tmp);
  }
  _signed = true;
}

std::ostream &operator<<(std::ostream &c, const Form &f) {
  c << "[ Form ]\n\"Name\": " << f.getName()
    << "\n\"Status\": " << f.getSignedFlag()
    << "\n\"Sign_Grade\": " << f.getSignedGrade()
    << "\n\"Exec_Grade\": " << f.getExecGrade() << '\n';
  return c;
}
