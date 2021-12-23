#ifndef _DIAMONDTRAP_H__
#define _DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _name;

public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);
  virtual ~DiamondTrap();

  // using ScavTrap::attack;
  virtual void attack(std::string const &target) const { ScavTrap::attack(target); }
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  std::string const &getName(void) const;

  void whoAmI(void);
};

std::ostream &operator<<(std::ostream &c, const DiamondTrap &diamond);

#endif
