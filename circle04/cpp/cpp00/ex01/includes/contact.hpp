#include <iostream>

#ifndef __CONTACT_H__
#define __CONTACT_H__

class Contact {
 private:
  std::string firstname_;
  std::string lastname_;
  std::string nickname_;
  std::string phonenumber_;
  std::string darkestsecret_;

 public:
  std::string GetFirstName() const { return firstname_; }
  std::string GetLastName() const { return lastname_; }
  std::string GetNickname() const { return nickname_; }
  std::string GetPhoneNumber() const { return phonenumber_; }
  std::string GetDarkestSecret() const { return darkestsecret_; }
  void SetFirstName(std::string str);
  void SetLastName(std::string str);
  void SetNickname(std::string str);
  void SetPhoneNumber(std::string str);
  void SetDarkestSecret(std::string str);
  void OutputFirstName();
  void OutputLastName();
  void OutputNicktName();
};

#endif