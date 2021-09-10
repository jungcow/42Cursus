#include "Zombie.hpp"

/*
** 생성 순서대로 destructor를 호출하는 것이 아닌, 그 역방향으로 파괴자를 호출한다.
** 왜?
** 먼저 생성된 것을 이용하여 그 다음 객체를 복사 생성할 때, 먼저 생성된 것을 지우게 되면,
** 얕은 복사일 땐 문제가 발생할 수 있다.
** 출처: https://www.geeksforgeeks.org/c-destructors-question-4/ 
*/

int main(void) {
  {
    std::cout << "\n[ Zombie In Stack ]\n"
              << std::endl;
    Zombie zom("zom");
    Zombie bie("bie");
    Zombie bie2("bie2");

    zom.announce();
    bie.announce();
    bie2.announce();
  }
  std::cout << "\n[ Zombie In Heap ]\n"
            << std::endl;
  Zombie *zom;
  Zombie *bie;
  {
    zom = newZombie("zom");
    bie = newZombie("bie");
    zom->announce();
  }
  std::cout << "\n[ Zombie RandomChumped ]\n"
            << std::endl;
  randomChump("Temp Zombie1");
  randomChump("Temp Zombie2");
  randomChump("Temp Zombie3");

  bie->announce();
  delete zom;
  delete bie;
  return (0);
}
