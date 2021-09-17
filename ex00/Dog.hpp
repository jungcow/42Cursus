#ifndef _DOG_H__
#define _DOG_H__

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  virtual ~Dog();
  Dog &operator=(const Dog &other);

  virtual void makeSound(void) const;
};

#endif