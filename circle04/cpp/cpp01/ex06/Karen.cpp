#include "Karen.hpp"

Karen::Karen() {
  _level[0] = "DEBUG";
  _level[1] = "INFO";
  _level[2] = "WARNING";
  _level[3] = "ERROR";
  _pf[0] = &Karen::debug;
  _pf[1] = &Karen::info;
  _pf[2] = &Karen::warning;
  _pf[3] = &Karen::error;
}

Karen::~Karen() {}

int Karen::find(const std::string level) {
  for (int i = 0; level.length() && (i < 4); i++) {
	if (_level[i] == level)
      return (i);
  }
  throw -1;
}

void Karen::debug() {
  std::cout << "[ DEBUG ]\n"
            << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n"
            << std::endl;
}

void Karen::info() {
  std::cout << "[ INFO ]\n"
            << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n"
            << std::endl;
}

void Karen::warning() {
  std::cout << "[ WARNING ]\n"
            << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.\n"
            << std::endl;
}

void Karen::error() {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable, I want to speak to the manager now.\n"
            << std::endl;
}

void Karen::complain(std::string level) {
  try {
    Level num = (Level)find(level);
    switch (num) {
      case DEBUG:
        debug();
      case INFO:
        info();
      case WARNING:
        warning();
      case ERROR:
        error();
    }
  } catch (int ret) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
  }
}
