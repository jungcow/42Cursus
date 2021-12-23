#ifndef _WRONG_ANIMAL_H__
#define _WRONG_ANIMAL_H__

#include <iostream>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  ~WrongAnimal();
  WrongAnimal &operator=(const WrongAnimal &other);

  std::string const &getType(void) const;

  void makeSound(void) const;
};

#endif