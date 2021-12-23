#include "HumanA.hpp"

HumanA::~HumanA() {
  std::cout << "<"
            << _name
            << "> Destructed"
            << std::endl;
}

const std::string &HumanA::getName() const {
  return _name;
}

void HumanA::setName(const std::string name) {
  _name = name;
}

void HumanA::attack() {
  std::cout << "<"
            << _name
            << "> attacks with his \""
            << _weapon.getType()
            << "\""
            << std::endl;
}