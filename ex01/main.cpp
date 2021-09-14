#include "ScavTrap.hpp"

int main(void) {
  ScavTrap aa("aa");
  ScavTrap bb("bbcc");
  ScavTrap cc = bb;

  cc.attack("bb");
  aa.takeDamage(cc.getAD());
  cc.attack("bb");
  bb.takeDamage(cc.getAD());
  bb.beRepaired(3);

  std::cout << "\n";
  std::cout << aa << std::endl;
  std::cout << bb << std::endl;
  std::cout << cc << std::endl;
  std::cout << "\n";

  cc.guardGate();
}