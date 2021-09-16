#ifndef _SCAVTRAP_H__
#define _SCAVTRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  ~ScavTrap();

  virtual void attack(std::string const &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  void guardGate(void);
};

std::ostream &operator<<(std::ostream &c, const ScavTrap &clap);

#endif
