#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog Constructed" << std::endl;
  type = "Dog";
}
Dog::~Dog() { std::cout << "Dog Constructed" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy Constructed" << std::endl;
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  type = other.type;
  return *this;
}

void Dog::makeSound(void) const { std::cout << "Wall Wall!" << std::endl; }
