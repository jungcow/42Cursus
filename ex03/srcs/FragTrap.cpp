#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "**FragTrap** Default Constructor called" << std::endl;
  setName("default");
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
  std::cout << "**FragTrap** Using name Constructor called" << std::endl;
  setName(name);
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "**FragTrap** Copy Constructor called" << std::endl;
  *this = other;
}

FragTrap::~FragTrap() {
  std::cout << "**FragTrap** Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  setName(other.getName());
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void FragTrap::attack(std::string const& target) {
  std::cout << "\n[ Attack ] FragTrap " << getName() << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints -= amount;
  std::cout << "\n[ Take Damage ] FragTrap " << getName() << " got a " << amount << " damages " << std::endl;
  std::cout << "So, The HP was cut from "
            << tmp << " to " << _hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints += amount;
  std::cout << "\n[ Repaired ] FragTrap " << getName() << " recovered " << amount << " HP" << std::endl;
  std::cout << "So, The HP was changed from "
            << tmp << " to " << _hitPoints << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[ Let's HighFives! ]\n"
            << std::endl;
}

std::ostream& operator<<(std::ostream& c, const FragTrap& frag) {
  c << "<"
    << frag.getName()
    << "> HP: " << frag.getHP()
    << " MP: " << frag.getMP()
    << " AD: " << frag.getAD();
  return c;
}
