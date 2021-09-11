#ifndef WEAPON_H__
#define WEAPON_H__

#include <iostream>

class Weapon {
 private:
  std::string _type;

 public:
  Weapon();
  Weapon(const std::string &type);
  Weapon(const Weapon &other);
  ~Weapon();

  const std::string &getType() const;
  void setType(std::string type);
};

#endif