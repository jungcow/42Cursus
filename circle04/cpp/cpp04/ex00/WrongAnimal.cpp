#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal Constructed" << std::endl;
}
WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy Constructed" << std::endl;
  *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  type = other.type;
  return *this;
}

std::string const &WrongAnimal::getType(void) const { return (type); }

void WrongAnimal::makeSound(void) const {
  std::cout << "No Sound!" << std::endl;
}
