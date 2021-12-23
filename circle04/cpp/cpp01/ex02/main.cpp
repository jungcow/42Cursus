#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *ptr = &str;
  std::string &ref = str;

  std::cout << "\n[ Display Address of String ]\n"
            << std::endl;
  std::cout << "&str: " << &str << std::endl;
  std::cout << "PTR: " << ptr << std::endl;
  std::cout << "&REF: " << &ref << std::endl;

  std::cout << "\n[ Display String ]\n"
            << std::endl;
  std::cout << "str: " << str << std::endl;
  std::cout << "*PTR: " << *ptr << std::endl;
  std::cout << "REF: " << ref << std::endl;
}