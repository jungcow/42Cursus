#include "phonebook.hpp"

using std::cout;

std::string CinWithEOF() {
  std::string input;
  std::cin >> input;
  if (std::cin.eof())
    exit(0);
  return (input);
}

void DrawTableRow() {
  cout << "├";
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j < 10; j++)
      cout << "─";
    if (i < 3)
      cout << "┼";
    else
      cout << "┤";
  }
  cout << std::endl;
}

void DrawTableTop() {
  cout << std::endl;
  cout << "┌";
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j < 10; j++)
      cout << "─";
    if (i < 3)
      cout << "┬";
    else
      cout << "┐";
  }
  cout << std::endl;
  cout << "│";
  cout << "  INDEX.  ";
  cout << "│";
  cout << "FIRST NAME";
  cout << "│";
  cout << "LAST NAME.";
  cout << "│";
  cout << "NICK NAME.";
  cout << "│";
  cout << std::endl;
  DrawTableRow();
}

void DrawTableBottom() {
  cout << "└";
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j < 10; j++)
      cout << "─";
    if (i < 3)
      cout << "┴";
    else
      cout << "┘";
  }
  cout << std::endl;
}