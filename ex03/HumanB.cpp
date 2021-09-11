#include "HumanB.hpp"

HumanB::HumanB() {
  _pWeapon = new Weapon();
  _isWeapon = false;
  _name = "Anonymous";
}

HumanB::HumanB(std::string name) {
  _isWeapon = false;
  _name = name;
}

HumanB::~HumanB() {
  if (_isWeapon)
    delete _pWeapon;
  std::cout << "<"
            << _name
            << "> Destructed"
            << std::endl;
}

const std::string &HumanB::getName() const {
  return _name;
}

void HumanB::setName(const std::string name) {
  _name = name;
}

void HumanB::createWeapon() {
  if (_isWeapon)
    delete _pWeapon;
  _pWeapon = new Weapon();
  _isWeapon = true;
  std::cout << "<"
            << _name
            << "> Created Weapon!"
            << std::endl;
}

void HumanB::createWeapon(const std::string type) {
  if (_isWeapon)
    delete _pWeapon;
  _pWeapon = new Weapon(type);
  _isWeapon = true;
  std::cout << "<"
            << _name
            << "> Created Weapon!"
            << std::endl;
}

void HumanB::deleteWeapon() {
  if (!_isWeapon) {
    std::cout << "<"
              << _name
              << "> No Weapon Yet..."
              << std::endl;
    return;
  }
  if (_isWeapon)
    delete _pWeapon;
  _isWeapon = false;
  std::cout << "<"
            << _name
            << "> Lost Weapon!"
            << std::endl;
}

void HumanB::attack() {
  if (!_isWeapon) {
    std::cout << "<"
              << _name
              << "> No Weapon... So, No Attack"
              << std::endl;
  } else {
    std::cout << "<"
              << _name
              << "> attacks with his "
              << _pWeapon->getType()
              << std::endl;
  }
}