#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal() {
  std::cout << "WrongDog Constructed" << std::endl;
  type = "WrongDog";
}
WrongDog::~WrongDog() { std::cout << "WrongDog Destructed" << std::endl; }

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other) {
  std::cout << "WrongDog Copy Constructed" << std::endl;
  *this = other;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
  type = other.type;
  return *this;
}

void WrongDog::makeSound(void) const { std::cout << "Wall Wall!" << std::endl; }
