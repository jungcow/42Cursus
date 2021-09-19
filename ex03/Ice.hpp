#ifndef _ICE_H__
#define _ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(std::string const &type);
  Ice(const Ice &other) : AMateria(other) {}
  Ice &operator=(const Ice &other);
  ~Ice() {}

  virtual Ice *clone() const;
  virtual void use(ICharacter &target);
};

#endif
