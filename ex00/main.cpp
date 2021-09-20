#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat a(3);
    Bureaucrat b("b", 148);

    try {
      std::cout << "\n==============[ Constructor, Destructor Exception Test "
                   "]============="
                << std::endl;

      Bureaucrat c(0);
      Bureaucrat d(151);
      std::cout << c << std::endl;
      std::cout << d << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout
        << "\n============================================================\n"
        << std::endl;
    try {
      std::cout << "\n==============[ increament, decrement Test ]============="
                << std::endl;
      Bureaucrat c(1);
      Bureaucrat d(150);

      std::cout << c << std::endl;
      std::cout << d << std::endl;
      c.decreaseGrade();
      d.increaseGrade();
      std::cout << c << std::endl;
      std::cout << d << std::endl;
    } catch (const std::exception &e) {
      std::cout << e.what() << '\n';
    }
    std::cout << "\n========================================================\n"
              << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << '\n';
  }
  return 0;
}
