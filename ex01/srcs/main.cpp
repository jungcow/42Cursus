#include "phonebook.hpp"

int main(void) {
  std::string input;
  PhoneBook phonebook;
  while (42) {
    std::cout << "\nCOMMANDS : [ADD, SEARCH, EXIT]\n"
              << "Choose in COMMANDS\n"
              << std::endl;
    std::cout << "COMMAND: ";
    input = CinWithEOF();
    if (input == "ADD")
      phonebook.AddContact();
    else if (input == "SEARCH")
      phonebook.SearchContact();
    else if (input == "EXIT")
      break;
  }
  return 0;
}
