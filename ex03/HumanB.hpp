#ifndef _HUMAN_B_H__
#define _HUMAN_B_H__

#include "Weapon.hpp"

class HumanB {
 private:
  Weapon *_pWeapon;
  bool _isWeapon;
  std::string _name;

 public:
  HumanB();
  HumanB(std::string name);
  ~HumanB();

  const std::string &getName() const;
  void setName(const std::string name);

  void createWeapon();
  void createWeapon(const std::string type);
  void deleteWeapon();

  void attack();
};

#endif