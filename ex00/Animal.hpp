#ifndef _ANIMAL_H__
#define _ANIMAL_H__

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
  // void               setType(const std::string &type_);

  virtual void makeSound(void) const;
};

#endif