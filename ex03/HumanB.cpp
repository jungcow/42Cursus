#include "HumanB.hpp"

#include <stdio.h>

HumanB::HumanB() {
  _pWeapon = NULL;
  _name = "Anonymous";
}

HumanB::HumanB(std::string name) {
  _pWeapon = NULL;
  _name = name;
}

HumanB::~HumanB() { std::cout << "<" << _name << "> Destructed" << std::endl; }

const std::string &HumanB::getName() const { return _name; }

void HumanB::setName(const std::string name) { _name = name; }

void HumanB::setWeapon(Weapon &weapon) {
  _pWeapon = &weapon;
  std::cout << "<" << _name << "> Created Weapon!" << std::endl;
}

void HumanB::attack() {
  if (!_pWeapon) {
    std::cout << "<" << _name << "> No Weapon... So, No Attack" << std::endl;
  } else {
    std::cout << "<" << _name << "> attacks with his \"" << _pWeapon->getType()
              << "\"" << std::endl;
  }
}