#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
  std::cout << "\n[ Human A ]\n"
            << std::endl;
  HumanA a1("a종족 1번", "도끼");
  HumanA a2("a종족 2번", "망치");
  HumanA a3("a종족 3번");
  HumanA a4;

  a1.attack();
  a2.attack();
  a3.attack();
  a4.attack();

  std::cout << "\n[ Human B ]\n"
            << std::endl;

  HumanB b1("b종족 1번");
  HumanB b2("b종족 2번");
  HumanB b3;

  b1.attack();
  b1.createWeapon("야구방망이");
  b1.attack();
  b1.deleteWeapon();
  b1.attack();

  std::cout << '\n';
  b2.createWeapon();
  b2.attack();

  std::cout << '\n';
  b3.createWeapon("수류탄");
  b3.attack();
  std::cout << '\n';

  HumanB b4("b4");
  b4.deleteWeapon();
  b4.createWeapon("미사일");
  b4.attack();
  b4.deleteWeapon();

  std::cout << std::endl;
  return (0);
}