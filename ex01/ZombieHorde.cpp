#include "Zombie.hpp"

Zombie *zombieHorde(int num, std::string name) {
	Zombie *zombie = new Zombie[num];

	for (int i=0; i<num; i++) {
		zombie[i].setName(name);
	}
	return zombie;
}