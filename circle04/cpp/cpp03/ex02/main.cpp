#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap aa("aa");
  ScavTrap bb("bbcc");
  ScavTrap cc = bb;
  FragTrap dd("dd");
  FragTrap ee("eeff");
  FragTrap ff = ee;

  cc.attack(aa.getName());
  aa.takeDamage(cc.getAD());
  cc.attack(bb.getName());
  bb.takeDamage(cc.getAD());
  bb.beRepaired(3);

  ff.attack(dd.getName());
  dd.takeDamage(ff.getAD());
  ff.attack(ee.getName());
  ee.takeDamage(ff.getAD());
  ee.beRepaired(3);

  std::cout << "\n";
  std::cout << aa << std::endl;
  std::cout << bb << std::endl;
  std::cout << cc << std::endl;
  std::cout << "\n";

  std::cout << "\n";
  std::cout << dd << std::endl;
  std::cout << ee << std::endl;
  std::cout << ff << std::endl;
  std::cout << "\n";

  cc.guardGate();
  ff.highFivesGuys();
}
