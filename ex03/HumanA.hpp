#ifndef _HUMAN_A_H__
#define _HUMAN_A_H__

#include "Weapon.hpp"

class HumanA {
 private:
  Weapon _weapon;
  std::string _name;

 public:
  HumanA() : _weapon() { _name = "Anonymous"; }
  HumanA(std::string name) : _weapon() { _name = name; }
  HumanA(std::string name, std::string type) : _weapon(type) { _name = name; }
  ~HumanA();

  const std::string &getName() const;
  void setName(const std::string name);
  void attack();
};

#endif