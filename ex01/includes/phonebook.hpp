#include <iostream>

#include "contact.hpp"

class PhoneBook {
 private:
  int num_;
  Contact Contact_[8];
  void OutputPreview();
  void OutputContact(const int index);

 public:
  PhoneBook() : Contact_() {
    num_ = 0;
  }
  void AddContact();
  void SearchContact();
};

void DrawTableRow();
void DrawTableTop();
void DrawTableBottom();

std::string CinWithEOF();
