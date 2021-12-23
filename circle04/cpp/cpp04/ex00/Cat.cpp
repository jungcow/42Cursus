#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Constructed" << std::endl;
  type = "Cat";
}
Cat::~Cat() { std::cout << "Cat Destructed" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy Constructed" << std::endl;
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  type = other.type;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Nyaong.. Nyaong.." << std::endl;
}
