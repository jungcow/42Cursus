#ifndef _WRONG_DOG_H__
#define _WRONG_DOG_H__

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
  WrongDog();
  WrongDog(const WrongDog &other);
  ~WrongDog();
  WrongDog &operator=(const WrongDog &other);

  void makeSound(void) const;
};

#endif