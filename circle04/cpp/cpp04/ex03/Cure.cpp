#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure &Cure::operator=(const Cure &other) {
	(void)other;
	return (*this);
}

Cure *Cure::clone() const { return (new Cure(_type)); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
