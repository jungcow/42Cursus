#ifndef _CLAPTRAP_H__
#define _CLAPTRAP_H__

#include <iostream>

class ClapTrap {
 private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

 public:
  /*
  ** string 클래스는 멤버 이니셜라이저 리스트로 초기화가 안된다..!
  */
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  const std::string& getName(void) const;
  int getHP(void) const;
  int getMP(void) const;
  int getAD(void) const;

  void setName(const std::string& name);
  void setHP(int hp);
  void setMP(int mp);
  void setAD(int ad);
};

std::ostream& operator<<(std::ostream& c, const ClapTrap& clap);

#endif