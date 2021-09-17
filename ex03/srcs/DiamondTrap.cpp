#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  std::cout << "**DiamondTrap** Default Constructor called\n" << std::endl;
  _name = "default";
  _energyPoints = 50;
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name), ScavTrap(name), FragTrap(name) {
  std::cout << "**DiamondTrap** Using name Constructor called\n" << std::endl;
  _name = name;
  _energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  std::cout << "**DiamondTrap** Copy Constructor called\n" << std::endl;
  *this = other;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "**DiamondTrap** Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void DiamondTrap::takeDamage(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints -= amount;
  std::cout << "\n[ Take Damage ] DiamondTrap " << _name << " got a " << amount
            << " damages " << std::endl;
  std::cout << "So, The HP was cut from " << tmp << " to " << _hitPoints
            << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
  unsigned int tmp = _hitPoints;
  _hitPoints += amount;
  std::cout << "\n[ Repaired ] DiamondTrap " << _name << " recovered " << amount
            << " HP" << std::endl;
  std::cout << "So, The HP was changed from " << tmp << " to " << _hitPoints
            << std::endl;
}

std::string const &DiamondTrap::getName(void) const { return _name; }

void DiamondTrap::whoAmI(void) {
  std::cout << "My name: <" << _name << ">, ClapTrap name: <"
            << ClapTrap::getName() << ">" << std::endl;
}

std::ostream &operator<<(std::ostream &c, const DiamondTrap &diamond) {
  c << "<" << diamond.getName() << "> HP: " << diamond.getHP()
    << " MP: " << diamond.getMP() << " AD: " << diamond.getAD();
  return c;
}
