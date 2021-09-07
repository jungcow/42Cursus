#include "phonebook.hpp"

using std::cout;

std::string CinWithEOF() {
  std::string input;
  std::getline(std::cin, input);
  if (std::cin.eof())
    exit(0);
  return (input);
}
