#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main(void) {
  {
    std::cout << "===============[ Yes, Virtual Function ]==============\n"
              << std::endl;
    const Animal *meta = new Animal();
    const Animal *i = new Cat();
    const Animal *j = new Dog();
    const Animal dog_copy = *j;

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << dog_copy.getType() << " " << std::endl;

    i->makeSound();
    dog_copy.makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }
  {
    std::cout << "\n===============[ No, Just Function ]==============\n"
              << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    const WrongAnimal *j = new WrongDog();
    const WrongAnimal wrongdog_copy = *j;

    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << wrongdog_copy.getType() << " " << std::endl;

    i->makeSound();
    wrongdog_copy.makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }
}