#ifndef _WRONG_CAT_H__
#define _WRONG_CAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);
  ~WrongCat();
  WrongCat &operator=(const WrongCat &other);

  void makeSound(void) const;
};

#endif