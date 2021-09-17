#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(std::string const &type) : AMateria(type) {}

Ice *Ice::clone() const { return (new Ice(_type)); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}