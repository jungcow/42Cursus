#ifndef _CAT_H__
#define _CAT_H__

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &other);
  virtual ~Cat();
  Cat &operator=(const Cat &other);

  virtual void makeSound(void) const;
};

#endif