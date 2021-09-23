#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "iter.hpp"

int main(void) {
  int    i[3] = {1, 2, 3};
  double d[3] = {1.1, 2.2, 3.3};

  std::string str[3] = {"hihi", "hello", "world"};

  iter(i, sizeof(i) / sizeof(i[0]), printArray);
  iter(d, sizeof(d) / sizeof(d[0]), printArray);
  iter(i, -2, printArray);
  iter(str, sizeof(str) / sizeof(str[0]), printArray);

  {
    ShrubberyCreationForm shru("shru");
    ShrubberyCreationForm bbery("bbery");
    ShrubberyCreationForm crea("crea");
    ShrubberyCreationForm shrubberyCreationForm[3] = {shru, bbery, crea};
    iter(shrubberyCreationForm,
         sizeof(shrubberyCreationForm) / sizeof(shrubberyCreationForm[0]),
         printArray);
  }
}