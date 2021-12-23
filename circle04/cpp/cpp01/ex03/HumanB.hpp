#ifndef _HUMAN_B_H__
#define _HUMAN_B_H__

#include "Weapon.hpp"

class HumanB {
 private:
  Weapon *_pWeapon;
  std::string _name;

 public:
  HumanB();
  HumanB(std::string name);
  ~HumanB();

  const std::string &getName() const;
  void setName(const std::string name);

  void setWeapon(Weapon &weapon);

  void attack();
};

#endif