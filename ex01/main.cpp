#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    try {
      std::cout
          << "\n==============[ Constructor Error Test ]==============\n\n";
      Form a("a", 0, 0);
      Form b("b", 160, 0);

      std::cout << a << '\n' << b << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    std::cout << "\n=================[ Main Test ]==================\n\n";

    Bureaucrat albert("Albert", 3);
    Form       paper("paper", 1, 1);
    Form       form("form", 4, 4);

    std::cout << albert << std::endl;
    std::cout << paper << std::endl;
    std::cout << form << std::endl;

    try {
      albert.signForm(form);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    std::cout << form << std::endl;

    try {
      albert.signForm(paper);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    std::cout << paper << std::endl;

    albert.increaseGrade();
    try {
      // paper.besigned(albert);
      albert.signForm(paper);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    std::cout << paper << std::endl;

    albert.increaseGrade();
    try {
      albert.signForm(paper);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
    std::cout << paper << std::endl;

    Form new_form("new", 10, 10);
    albert.signForm(new_form);
    std::cout << form << std::endl;

    albert.decreaseGrade();
    albert.decreaseGrade();
    albert.decreaseGrade();
    albert.decreaseGrade();
    Form form2("form2", 3, 3);
    albert.signForm(form2);

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
