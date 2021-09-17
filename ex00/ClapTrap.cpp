#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  std::cout << "Default Constructor called" << std::endl;
  _name = "Default";
  _hitPoints = 10;
  _energyPoints = 10;
  _attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string& name) {
  std::cout << "Using name Constructor called" << std::endl;
  _name = name;
  _hitPoints = 10;
  _energyPoints = 10;
  _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  std::cout << "Copy Constructor called" << std::endl;
  *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

std::ostream& operator<<(std::ostream& c, const ClapTrap& clap) {
  c << "<"
    << clap.getName()
    << "> HP: " << clap.getHP();
  return c;
}

std::string const & ClapTrap::getName(void) const {
  return _name;
}
int ClapTrap::getHP(void) const {
  return _hitPoints;
}
int ClapTrap::getMP(void) const {
  return _energyPoints;
}
int ClapTrap::getAD(void) const {
  return _attackDamage;
}

void ClapTrap::setName(const std::string& name) {
  _name = name;
}
void ClapTrap::setHP(int hp) {
  _hitPoints = hp;
}
void ClapTrap::setMP(int mp) {
  _energyPoints = mp;
}
void ClapTrap::setAD(int ad) {
  _attackDamage = ad;
}

ClapTrap::~ClapTrap() {
  std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(std::string const& target) const {
  std::cout << "\n[ Attack ] ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints -= amount;
  std::cout << "\n[ Take Damage ] ClatTrap " << _name << " got a " << amount << " damages " << std::endl;
  std::cout << "So, The HP was cut from "
            << tmp << " to " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints += amount;
  std::cout << "\n[ Repaired ] ClatTrap " << _name << " recovered " << amount << " HP" << std::endl;
  std::cout << "So, The HP was changed from "
            << tmp << " to " << _hitPoints << std::endl;
}
