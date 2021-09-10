#include "Zombie.hpp"

void Zombie::announce() {
  std::cout << "<"
            << _name
            << "> BraiiiiiiinnnzzzZ..."
            << std::endl;
}

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
  _name = name;
}

Zombie::~Zombie() {
  std::cout << "<"
            << _name
            << "> Destructed"
            << std::endl;
}

void Zombie::setName(std::string name) {
  _name = name;
}