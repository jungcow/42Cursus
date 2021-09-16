#ifndef _DIAMONDTRAP_H__
#define _DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);
  virtual ~DiamondTrap();

  // using ScavTrap::attack;
  virtual void attack(std::string const &target) { ScavTrap::attack(target); }
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  const std::string &getName(void) const;

  void whoAmI(void);
};

std::ostream &operator<<(std::ostream &c, const DiamondTrap &diamond);

#endif