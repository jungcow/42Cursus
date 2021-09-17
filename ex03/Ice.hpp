#ifndef _ICE_H__
#define _ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
  Ice(std::string const &type);
  ~Ice() {}

  virtual Ice *clone() const;
  virtual void use(ICharacter &target);
};

#endif