#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog Constructed" << std::endl;
  type = "Dog";
  _brain = new Brain("Dog Brain");
}

Dog::~Dog() {
  std::cout << "Dog Destructed" << std::endl;
  delete _brain;
}

Dog::Dog(const std::string &idea) : Animal() {
  std::cout << "Dog using str Constructed" << std::endl;
  _brain = new Brain(idea);
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy Constructed" << std::endl;
  _brain = new Brain();
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  type = other.type;
  *_brain = *other._brain;
  return *this;
}

void Dog::makeSound(void) const { std::cout << "Wall Wall!" << std::endl; }

void Dog::outputBrain(void) const { _brain->outputIdeas(); }
void Dog::setBrain(const std::string &idea) { _brain->setIdea(idea); }
