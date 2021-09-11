#ifndef _HUMAN_A_H__
#define _HUMAN_A_H__

#include "Weapon.hpp"

class HumanA {
 private:
  const Weapon &_weapon;  //왜 const여야 하나?
  std::string _name;

 public:
  HumanA(const Weapon &weapon) : _weapon(weapon) { _name = "Anonymous"; }
  HumanA(std::string name, const Weapon &weapon) : _weapon(weapon) { _name = name; }
  ~HumanA();

  const std::string &getName() const;
  void setName(const std::string name);

  void attack();
};

#endif