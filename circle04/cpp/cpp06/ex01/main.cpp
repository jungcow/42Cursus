#include "Serialization.hpp"

int main(void) {
  Serialization serial;

  serial.setRaw(serial.serialize(serial.getData()));

  Serialization serial2("jung", 10);

  std::cout << "\n[ origin ]\n";
  std::cout << serial2.getData()->password << std::endl;
  std::cout << serial2.getData()->number << std::endl;
  std::cout << serial2.getData()->password2 << "\n\n";

  serial2.setRaw(serial.getRaw());
  serial2.setData(serial2.deserialize(serial2.getRaw()));

  std::cout << "[ After Receiving ]\n";
  std::cout << serial2.getData()->password << std::endl;
  std::cout << serial2.getData()->number << std::endl;
  std::cout << serial2.getData()->password2 << std::endl;
}