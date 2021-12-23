#include "ClapTrap.hpp"

int main(void) {
  ClapTrap a("aaaa");
  ClapTrap b;

	a.attack(b.getName());

	b.takeDamage(a.getAD());
	b.beRepaired(5);
	
	std::cout << "\n";
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "\n";
	return (0);
}
