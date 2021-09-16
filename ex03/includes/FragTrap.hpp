#ifndef _FRAGTRAP_H__
#define _FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  ~FragTrap();

  virtual void attack(std::string const &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  void highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &c, const FragTrap &clap);

#endif