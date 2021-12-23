#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Constructed" << std::endl;
  type = "Cat";
  _brain = new Brain("Cat Brain");
  // for (int i = 0; i < 100; i++) {
  //   _brain->_ideas[i] = "Cat Brain";
  // }
}
Cat::~Cat() {
  std::cout << "Cat Destructed" << std::endl;
  delete _brain;
}

Cat::Cat(const std::string &idea) : Animal() {
  std::cout << "Cat using str Constructed" << std::endl;
  _brain = new Brain(idea);
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy Constructed" << std::endl;
  _brain = new Brain();
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  type = other.type;
  *_brain = *other._brain;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Nyaong.. Nyaong.." << std::endl;
}

void Cat::outputBrain(void) const { _brain->outputIdeas(); }
void Cat::setBrain(const std::string &idea) { _brain->setIdea(idea); }
