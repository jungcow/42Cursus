#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");

  AMateria *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  {
    std::cout << "\n==================[ deep copy & exception test "
                 "]==================="
              << std::endl;
    *(Character *)bob = *(Character *)me;
    bob->use(0, *me);
    bob->use(1, *me);
    bob->use(2, *me);
    tmp = src->createMateria("NO MATCH");
    if (tmp == NULL)
      std::cout << "[ Main.cpp Error ] No Materia Matched" << std::endl;
    src->learnMateria(new Cure());
    src->learnMateria(NULL);
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    tmp = src->createMateria("cure");
    bob->equip(tmp);
    tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("ice");
    bob->equip(tmp);

    ICharacter *jung = new Character("jung");
    bob->use(0, *jung);
    bob->use(1, *jung);
    bob->use(2, *jung);
    bob->use(3, *jung);
    bob->use(4, *jung);

    bob->unequip(4);
    bob->unequip(3);
    bob->unequip(2);
    bob->unequip(1);
    bob->unequip(0);
    bob->unequip(-1);

    bob->use(0, *jung);
    bob->use(1, *jung);
    bob->use(2, *jung);
    bob->use(3, *jung);
    bob->use(4, *jung);
    delete jung;
    std::cout << "============================================================="
                 "=======\n"
              << std::endl;
  }

  delete bob;
  delete me;
  delete src;

  return 0;
}
