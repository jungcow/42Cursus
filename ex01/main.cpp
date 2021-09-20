#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    std::cout << "\n==============[ Constructor Error Test ]==============\n\n";
    Form a("a", 0, 0);
    Form b("b", 160, 0);

    std::cout << a << '\n' << b << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << "\n===================[ Main Test ]====================\n\n";

  std::cout << "----[ Before Test ]----\n";
  Bureaucrat albert("Albert", 3);
  Form       paper("paper", 1, 1);
  Form       form("form", 4, 4);

  std::cout << albert << '\n';
  std::cout << paper << '\n';
  std::cout << form << '\n';

  std::cout << "\n----[ Start Test ]----\n";
  try {
    albert.signForm(form);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << form << '\n';

  try {
    albert.signForm(paper);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << paper << '\n';

  albert.increaseGrade();
  try {
    albert.signForm(paper);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << paper << '\n';

  albert.increaseGrade();
  try {
    albert.signForm(paper);
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << paper << std::endl;

  return 0;
}
