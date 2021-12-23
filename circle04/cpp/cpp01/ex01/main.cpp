#include "Zombie.hpp"

int main(void) {
  Zombie *pZom, *pBie;

  pZom = zombieHorde(3, "ZOM");
  for (int i = 0; i < 3; i++) {
    pZom[i].announce();
  }

  pBie = zombieHorde(5, "BIE");
  for (int i = 0; i < 5; i++) {
    pBie[i].announce();
  }

  delete[] pZom;
  delete[] pBie;
  return (0);
}