#include "Animal.hpp"

Animal::Animal() { std::cout << "Animal Constructed" << std::endl; }
Animal::~Animal() { std::cout << "Animal Destructed" << std::endl; }

Animal::Animal(const Animal &other) {
  std::cout << "Animal Copy Constructed" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal &other) {
  type = other.type;
  return *this;
}

std::string const &Animal::getType(void) const { return (type); }

void Animal::outputBrain(void) const {}

void Animal::makeSound(void) const { std::cout << "No Sound!" << std::endl; }
