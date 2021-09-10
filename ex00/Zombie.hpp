#ifndef ZOMBIE_H__
#define ZOMBIE_H__

#include <iostream>

class Zombie {
 private:
  std::string _name;

 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif