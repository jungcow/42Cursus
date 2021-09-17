#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat Constructed" << std::endl;
  type = "WrongCat";
}
WrongCat::~WrongCat() { std::cout << "WrongCat Destructed" << std::endl; }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat Copy Constructed" << std::endl;
  *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  type = other.type;
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "Nyaong.. Nyaong.." << std::endl;
}
