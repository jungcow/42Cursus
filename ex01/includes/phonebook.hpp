#include <iostream>

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "contact.hpp"

class PhoneBook {
 private:
  int num_;
  Contact Contact_[8];
  void OutputPreview();
  void OutputContact(const int index);
  bool TryScanContactNumber(const int num);
  void CatchNoContactError();
  int InputSearchingIndex();
  bool TrySearchingIndex(const int index);
  void CatchInputError();
  static void DrawTableRow();
  static void DrawTableTop();
  static void DrawTableBottom();

 public:
  PhoneBook() : Contact_() {
    num_ = 0;
  }
  void AddContact();
  void SearchContact();
  int CheckCommand(std::string input);
};

std::string CinWithEOF();

#endif