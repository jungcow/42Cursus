#include "ScalarType.hpp"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "[ Error ] Put one or more parameters any type you want\n";
    return (0);
  }
  for (int i = 1; i < argc; i++) {
    if (!(*argv[i]))
      continue;
    ScalarType scalar(argv[i]);
    scalar.convertType();
    scalar.outputType();
    if (i != argc - 1)
      std::cout << '\n';
  }
}