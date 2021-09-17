#ifndef _ANIMAL_H__
#define _ANIMAL_H__

#include "Brain.hpp"
#include <iostream>

class Animal {
protected:
  std::string type;

public:
  Animal();
  Animal(const Animal &other);
  virtual ~Animal();
  Animal &operator=(const Animal &other);

  std::string const &getType(void) const;
  virtual void       outputBrain(void) const = 0;
  virtual void       makeSound(void) const = 0;
};

#endif
