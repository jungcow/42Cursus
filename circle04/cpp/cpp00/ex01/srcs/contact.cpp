#include "contact.hpp"

#include <iomanip>

void Contact::SetFirstName(std::string str) {
  firstname_ = str;
}
void Contact::SetLastName(std::string str) {
  lastname_ = str;
}
void Contact::SetNickname(std::string str) {
  nickname_ = str;
}
void Contact::SetPhoneNumber(std::string str) {
  phonenumber_ = str;
}
void Contact::SetDarkestSecret(std::string str) {
  darkestsecret_ = str;
}

void Contact::OutputFirstName() {
  if (firstname_.length() <= 10) {
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << firstname_;
  } else {
    std::cout << firstname_.substr(0, 9);
    std::cout << ".";
  }
}
void Contact::OutputLastName() {
  if (lastname_.length() <= 10) {
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << lastname_;
  } else {
    std::cout << lastname_.substr(0, 9);
    std::cout << ".";
  }
}
void Contact::OutputNicktName() {
  if (nickname_.length() <= 10) {
    std::cout << std::setfill(' ') << std::setw(10);
    std::cout << nickname_;
  } else {
    std::cout << nickname_.substr(0, 9);
    std::cout << ".";
  }
}