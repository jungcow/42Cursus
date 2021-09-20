#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat bu("bu", 150);
  Bureaucrat re("re", 140);
  Bureaucrat au("au", 100);
  Bureaucrat cr("cr", 50);
  Bureaucrat at("at", 5);

  Form *forms[3] = {new ShrubberyCreationForm("Shru"),
                    new RobotomyRequestForm("Robo"),
                    new PresidentialPardonForm("Pres")};
  std::cout << "[ No Sign Error Test ]\n\n";
  for (int i = 0; i < 3; i++) {
    bu.executeForm(*forms[i]);
    re.executeForm(*forms[i]);
    au.executeForm(*forms[i]);
    cr.executeForm(*forms[i]);
    at.executeForm(*forms[i]);
	std::cout << '\n';
  }

  std::cout << "\n[ Can you Sign Test ]\n\n";
  for (int i = 0; i < 3; i++) {
    bu.signForm(*forms[i]);
    re.signForm(*forms[i]);
    au.signForm(*forms[i]);
    cr.signForm(*forms[i]);
    at.signForm(*forms[i]);
	std::cout << '\n';
  }

  std::cout << "\n[ Can you Exec Test ]\n\n";
  for (int i = 0; i < 3; i++) {
    bu.executeForm(*forms[i]);
    re.executeForm(*forms[i]);
    au.executeForm(*forms[i]);
    cr.executeForm(*forms[i]);
    at.executeForm(*forms[i]);
	std::cout << '\n';
  }
  for (int i = 0; i < 3; i++) {
    delete forms[i];
  }
}
