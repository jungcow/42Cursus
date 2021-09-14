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
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap& operator=(const DiamondTrap& other);
  ~DiamondTrap();

  using ScavTrap::attack;
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  const std::string& getName(void) const;
  int getHP(void) const;
  int getMP(void) const;
  int getAD(void) const;

  void whoAmI(void);
};

std::ostream& operator<<(std::ostream& c, const DiamondTrap& diamond);

#endif