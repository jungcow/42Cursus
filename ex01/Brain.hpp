#ifndef _BRAIN_H__
#define _BRAIN_H__

#include <iostream>

class Brain {
public:
  std::string _ideas[100];
  Brain();
  Brain(const Brain &other);
  Brain(const std::string &idea);
  ~Brain();
  Brain &operator=(const Brain &other);

  void               outputIdeas(void) const;
  std::string const &getIdea(void) const;
  void               setIdea(const std::string &idea);
};

#endif