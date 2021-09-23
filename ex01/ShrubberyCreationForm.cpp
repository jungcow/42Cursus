#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("Shrubbery", 145, 137), _target("Anonymous") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form("Shrubbery", 145, 137), _target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  (void)other;
  return *this;
}

std::string const &ShrubberyCreationForm::getTarget() const {
  return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::fstream ws;
  ws.exceptions(std::fstream::failbit | std::fstream::badbit);
  ws.open(_target + "_shrubbery", std::fstream::out | std::fstream::app);
  ws << "            .        +          .      .          .\n";
  ws << "     .            _        .                    .\n";
  ws << "  ,              /;-._,-.____        ,-----.__\n";
  ws << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n";
  ws << "  `                 \\   _|`'=:_::.`.);  \\ __/ /\n";
  ws << "                      ,    `./  \\:. `.   )==-'  .\n";
  ws << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n";
  ws << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n";
  ws << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n";
  ws << "  .      ,=':  \\    ` `/` ' , , ,:' `'--'.--'---._/`7\n";
  ws << "   `.   (    \\: \\,-._` ` + '\\, ,'   _,--._,---':.__/\n";
  ws << "              \\:  `  X` _| _,\\/'   .-'\n";
  ws << ".               ':._:`\\____  /:'  /      .           .\n";
  ws << "                    \\::.  :\\/:'  /              +\n";
  ws << "   .                 `.:.  /:'  }      .\n";
  ws << "           .           ):_(:;   \\           .\n";
  ws << "                      /:. _/ ,  |\n";
  ws << "                   . (|::.     ,`                  .\n";
  ws << "     .                |::.    {\\n";
  ws << "                      |::.\\  \\ `.\n";
  ws << "                     |:::(    |\n";
  ws << "              O       |:::/{ }  |                  (\n";
  ws << "               )  ___/#\\::`/ (O '==._____   O, (O  /`\n";
  ws << "          ~~~w/w~'~~,\\` `:/,-(~`'~~~~~~~~'~o~\\~/~w|/~\n";
  ws << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\n";
}

std::ostream &operator<<(std::ostream &c, const ShrubberyCreationForm &f) {
  c << "[ Form ]\n\"Name\": " << f.getName()
    << "\n\"Target\": " << f.getTarget()
    << "\n\"Status\": " << f.getSignedFlag()
    << "\n\"Sign_Grade\": " << f.getSignedGrade()
    << "\n\"Exec_Grade\": " << f.getExecGrade() << '\n';
  return c;
}
