#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  {
    std::cout << "==============[ Simple Test ]==============" << std::endl;
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j; // should not create a leak
    delete i;
  }
  std::cout << "\n============[ Array Test ]============" << std::endl;

  const Animal *array[10];

  std::cout << "\n-----------( 5 Dogs Constructed )---------" << std::endl;
  int i = 0;
  while (i < 5) {
    array[i++] = new Dog();
  }
  std::cout << "------------------------------------------" << std::endl;

  std::cout << "\n-----------( 5 Cats Constructed )---------" << std::endl;
  while (i < 10) {
    array[i++] = new Cat();
  }
  std::cout << "------------------------------------------" << std::endl;

  std::cout << std::endl;
  i = 0;
  while (i < 10) {
    array[i++]->makeSound();
  }
  std::cout << "\n";
  i = 0;
  while (i < 10) {
    array[i]->outputBrain();
    delete array[i++];
    std::cout << "\n";
  }
  {
    std::cout << "\n-----------( Dog Assignment operator Test )---------"
              << std::endl;
    Dog dog1("dog1");
    Dog dog2("dog2");
    Dog dog3("dog3");
    std::cout << "[ Before Copy ]" << std::endl;
    dog1.outputBrain();
    dog2.outputBrain();
    std::cout << "\n[ After Copy ]" << std::endl;
    dog1 = dog2;
    dog1.outputBrain();
    dog2.outputBrain();
    std::cout << "\n[ After Copy changed - for Deep ]" << std::endl;
    dog2 = dog3;
    dog1.outputBrain();
    dog2.outputBrain();
    dog3.outputBrain();
  }
  {
    std::cout << "\n-----------( cat Assignment operator Test )---------"
              << std::endl;
    Cat cat1("cat1");
    Cat cat2("cat2");
    Cat cat3("cat3");
    std::cout << "[ Before Copy ]" << std::endl;
    cat1.outputBrain();
    cat2.outputBrain();
    std::cout << "\n[ After Copy ]" << std::endl;
    cat1 = cat2;
    cat1.outputBrain();
    cat2.outputBrain();
    std::cout << "\n[ After Copy changed - for Deep ]" << std::endl;
    cat2 = cat3;
    cat1.outputBrain();
    cat2.outputBrain();
    cat3.outputBrain();
  }
}
