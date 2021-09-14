#ifndef _SCAVTRAP_H__
#define _SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
 public:
  ScavTrap() : ClapTrap() {
    std::cout << "**ScavTrap** Default Constructor called" << std::endl;
  }
  ScavTrap(const std::string name) : ClapTrap(name) {
    std::cout << "**ScavTrap** Using name Constructor called" << std::endl;
  }
  ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "**ScavTrap** Copy Constructor called" << std::endl;
  }
  ScavTrap& operator=(const ScavTrap& other);

  ~ScavTrap() {
    std::cout << "**ScavTrap** Destructor called" << std::endl;
  }

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void guardGate(void);
};

std::ostream& operator<<(std::ostream& c, const ScavTrap& clap);

#endif