#ifndef _DOG_H__
#define _DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *_brain;

public:
  Dog();
  Dog(const Dog &other);
  Dog(const std::string &idea);
  virtual ~Dog();
  Dog &operator=(const Dog &other);

  virtual void makeSound(void) const;
  virtual void outputBrain(void) const;
  void         setBrain(const std::string &idea);
};

#endif