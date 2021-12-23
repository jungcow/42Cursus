#ifndef _CAT_H__
#define _CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_brain;

public:
  Cat();
  Cat(const Cat &other);
  Cat(const std::string &idea);
  virtual ~Cat();
  Cat &operator=(const Cat &other);

  virtual void makeSound(void) const;
  void         outputBrain(void) const;
  void         setBrain(const std::string &idea);
};

#endif