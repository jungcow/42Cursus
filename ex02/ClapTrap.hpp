#ifndef _CLAPTRAP_H__
#define _CLAPTRAP_H__

#include <iostream>

class ClapTrap {
private:
  std::string _name;
  /*
  ** 상속을 위해 protected로 변경함
  */
protected:
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

public:
  ClapTrap();
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);
  ~ClapTrap();

  virtual void attack(std::string const &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  const std::string &getName(void) const;
  int                getHP(void) const;
  int                getMP(void) const;
  int                getAD(void) const;

  void setName(const std::string &name);
  void setHP(int hp);
  void setMP(int mp);
  void setAD(int ad);
};

std::ostream &operator<<(std::ostream &c, const ClapTrap &clap);

#endif