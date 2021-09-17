#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain Constructed" << std::endl;
  setIdea("\0");
}

Brain::Brain(const Brain &other) {
  std::cout << "Brain Copy Constructed" << std::endl;
  *this = other;
}
Brain::Brain(const std::string &idea) {
  std::cout << "Brain using str Constructed" << std::endl;
  setIdea(idea);
}

Brain::~Brain() { std::cout << "Brain Destructed" << std::endl; }

Brain &Brain::operator=(const Brain &other) {
  for (int i = 0; i < 100; i++) {
    _ideas[i] = other._ideas[i];
  }
  return *this;
}

void Brain::outputIdeas(void) const {
  std::cout << "[ ";
  for (int i = 0; i < 100; i++) {
    std::cout << _ideas[i];
    if (i < 99)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}
std::string const &Brain::getIdea(void) const { return (*_ideas); }

void Brain::setIdea(const std::string &idea) {
  for (int i = 0; i < 100; i++) {
    _ideas[i] = idea;
  }
}
