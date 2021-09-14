#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "**ScavTrap** Default Constructor called" << std::endl;
  setName("default");
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
  std::cout << "**ScavTrap** Using name Constructor called" << std::endl;
  setName(name);
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "**ScavTrap** Copy Constructor called" << std::endl;
  *this = other;
}

ScavTrap::~ScavTrap() {
  std::cout << "**ScavTrap** Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  setName(other.getName());
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  std::cout << "\n[ Attack ] ScavTrap " << getName() << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints -= amount;
  std::cout << "\n[ Take Damage ] ScavTrap " << getName() << " got a " << amount << " damages " << std::endl;
  std::cout << "So, The HP was cut from "
            << tmp << " to " << _hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints += amount;
  std::cout << "\n[ Repaired ] ScavTrap " << getName() << " recovered " << amount << " HP" << std::endl;
  std::cout << "So, The HP was changed from "
            << tmp << " to " << _hitPoints << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "[ ScavTrap has enterred in GateKeeper Mode! ]\n"
            << std::endl;
}

std::ostream& operator<<(std::ostream& c, const ScavTrap& scav) {
  c << "<"
    << scav.getName()
    << "> HP: " << scav.getHP()
    << " MP: " << scav.getMP()
    << " AD: " << scav.getAD();
  return c;
}
