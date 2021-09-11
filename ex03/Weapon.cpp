#include "Weapon.hpp"

Weapon::Weapon() {
  _type = "주먹";
}
Weapon::Weapon(const std::string &type) {
  _type = type;
}

Weapon::Weapon(const Weapon &other) {
  _type = other.getType();
}

Weapon::~Weapon() {
  /* weapon에 nullptr이 들어갈 수 없으니깐 안심하고 해제해도 됨 */
}

const std::string &Weapon::getType() const {
  return _type;
}

void Weapon::setType(std::string type) {
  _type = type;
}