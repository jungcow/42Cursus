#include "phonebook.hpp"

void TellCommands() {
  std::cout << "\nCOMMANDS : [ADD, SEARCH, EXIT]\n"
            << "Choose in COMMANDS\n"
            << std::endl;
  std::cout << "COMMAND: ";
}

int main(void) {
  std::string input;
  PhoneBook phonebook;
  while (42) {
    TellCommands();
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
