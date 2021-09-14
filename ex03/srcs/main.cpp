#include "DiamondTrap.hpp"

int main(void) {
  {
    std::cout << "\n=====================[ ScavTrap Test ]=====================\n"
              << std::endl;

    ScavTrap aa("aa");
    ScavTrap bb("bbcc");
    ScavTrap cc = bb;

    std::cout << "\n";
    std::cout << aa << std::endl;
    std::cout << bb << std::endl;
    std::cout << cc << std::endl;

    cc.attack(aa.getName());
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
  {
    std::cout << "\n=====================[ FragTrap Test ]=====================\n"
              << std::endl;
    FragTrap dd("dd");
    FragTrap ee("eeff");
    FragTrap ff = ee;

    std::cout << "\n";
    std::cout << dd << std::endl;
    std::cout << ee << std::endl;
    std::cout << ff << std::endl;

    ff.attack(dd.getName());
    dd.takeDamage(ff.getAD());
    ff.attack("ee");
    ee.takeDamage(ff.getAD());
    ee.beRepaired(3);

    std::cout << "\n";
    std::cout << dd << std::endl;
    std::cout << ee << std::endl;
    std::cout << ff << std::endl;
    std::cout << "\n";

    ff.highFivesGuys();
  }
  {
    std::cout << "\n=====================[ DiamondTrap Test ]=====================\n"
              << std::endl;
    DiamondTrap dia("dia");
    DiamondTrap mond = std::string("mond");
    DiamondTrap anonymous;

    std::cout << dia << std::endl;
    std::cout << mond << std::endl;
    std::cout << anonymous << std::endl;

    dia.attack("mond");
    mond.takeDamage(dia.getAD());
    mond.beRepaired(10);
    anonymous.attack("dia");
    dia.takeDamage(anonymous.getAD());
    dia.beRepaired(8);

    std::cout << "\n";
    dia.whoAmI();
    mond.whoAmI();
    anonymous.whoAmI();

    std::cout << "\n";
    std::cout << dia << std::endl;
    std::cout << mond << std::endl;
    std::cout << anonymous << std::endl;
    std::cout << "\n";
  }
  return (0);
}