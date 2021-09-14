#include "ScavTrap.hpp"

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  std::cout << "\n[ Attack ] ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints -= amount;
  std::cout << "\n[ Take Damage ] ScavTrap " << _name << " got a " << amount << " damages " << std::endl;
  std::cout << "So, The HP was cut from "
            << tmp << " to " << _hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints += amount;
  std::cout << "\n[ Repaired ] ScavTrap " << _name << " recovered " << amount << " HP" << std::endl;
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
    << "> HP: " << scav.getHP();
  return c;
}
