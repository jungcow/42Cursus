#include "Karen.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Only One Argument" << std::endl;
    return (0);
  }
  Karen karen;
  karen.complain(argv[1]);
  return (0);
}
