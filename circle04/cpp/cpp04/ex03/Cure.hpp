#ifndef _CURE_H__
#define _CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(std::string const &type);
  Cure(const Cure &other) : AMateria(other) {}
  Cure &operator=(const Cure &other);
  ~Cure() {}

  virtual Cure *clone() const;
  virtual void  use(ICharacter &target);
};

#endif
