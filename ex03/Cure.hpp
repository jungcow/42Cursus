#ifndef _CURE_H__
#define _CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(std::string const &type);
  ~Cure() {}

  virtual Cure *clone() const;
  virtual void  use(ICharacter &target);
};

#endif