#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form(145, 137), _target("Anonymous") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form(145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : Form(145, 137), _target(other.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  return *this;
}

std::string const &ShrubberyCreationForm::getTarget() const {
  return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  Form::execute(executor);
  std::fstream ws;
  try {
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
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
