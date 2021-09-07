#include "phonebook.hpp"

#include <iomanip>

using std::cout;

void PhoneBook::DrawTableRow() {
  cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
}

void PhoneBook::DrawTableTop() {
  cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
       << "│  INDEX.  │FIRST NAME│LAST NAME.│NICK NAME.│\n"
       << "├──────────┼──────────┼──────────┼──────────┤\n";
}

void PhoneBook::DrawTableBottom() {
  cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::OutputPreview() {
  DrawTableTop();
  for (int i = 0; i < num_; i++) {
    cout << "│";
    cout << std::setfill(' ') << std::setw(10);
    cout << i + 1;
    cout << "│";
    Contact_[i].OutputFirstName();
    cout << "│";
    Contact_[i].OutputLastName();
    cout << "│";
    Contact_[i].OutputNicktName();
    cout << "│";
    cout << std::endl;
    if (i < num_ - 1)
      DrawTableRow();
    else
      DrawTableBottom();
  }
}

void PhoneBook::OutputContact(const int index) {
  cout << "\n-------------[INDEX: " << index << "]-------------" << std::endl;
  cout << "[ FIRST NAME ] : " << Contact_[index - 1].GetFirstName() << std::endl;
  cout << "[ LAST NAME ] : " << Contact_[index - 1].GetLastName() << std::endl;
  cout << "[ NICK NAME ] : " << Contact_[index - 1].GetNickname() << std::endl;
  cout << "[ PHONE NUMBER ] : " << Contact_[index - 1].GetPhoneNumber() << std::endl;
  cout << "[ SECRET NUMBER ] : " << Contact_[index - 1].GetDarkestSecret() << std::endl;
  cout << "------------------------------------" << std::endl;
}

bool PhoneBook::TryScanContactNumber(const int num) {
  if (num > 0)
    return (true);
  return (false);
}

void PhoneBook::CatchNoContactError() {
  cout << "[🔺 Sorry, No Contact here]" << std::endl;
}

int PhoneBook::InputSearchingIndex() {
  int index;
  cout << "\nEnter a Index: ";
  std::cin >> index;
  return (index);
}

bool PhoneBook::TrySearchingIndex(int index) {
  if (index > 0 && index <= num_) {
    OutputContact(index);
    return (true);
  }
  return (false);
}

void PhoneBook::CatchInputError() {
  if (std::cin.fail()) {
    if (std::cin.eof())
      exit(0);
    cout << "❌ Hey, Put Integer for Index ❌\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
  } else
    cout << "❌ WRONG RANGE ERROR ❌: Check Index" << std::endl;
}

void PhoneBook::SearchContact() {
  if (TryScanContactNumber(num_)) {
    OutputPreview();
    while (true) {
      if (!TrySearchingIndex(InputSearchingIndex()))
        CatchInputError();
      else
        break;
    }
  } else
    CatchNoContactError();
}

void PhoneBook::AddContact() {
  cout << "\n[Please Fill In The Form]\n"
       << std::endl;
  if (num_ == 8) {
    for (int i = 1; i < 8; i++) {
      Contact_[i - 1].SetFirstName(Contact_[i].GetFirstName());
      Contact_[i - 1].SetLastName(Contact_[i].GetLastName());
      Contact_[i - 1].SetNickname(Contact_[i].GetNickname());
      Contact_[i - 1].SetPhoneNumber(Contact_[i].GetPhoneNumber());
      Contact_[i - 1].SetDarkestSecret(Contact_[i].GetDarkestSecret());
    }
    num_ -= 1;
  }
  cout << "FIRST NAME: ";
  Contact_[num_].SetFirstName(CinWithEOF());
  cout << "LAST NAME: ";
  Contact_[num_].SetLastName(CinWithEOF());
  cout << "NICK NAME: ";
  Contact_[num_].SetNickname(CinWithEOF());
  cout << "PHONE NUMBER: ";
  Contact_[num_].SetPhoneNumber(CinWithEOF());
  cout << "DARKEST SECRET: ";
  Contact_[num_].SetDarkestSecret(CinWithEOF());
  num_ += 1;
}