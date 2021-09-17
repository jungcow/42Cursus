#ifndef _A_MATERIA_H__
#define _A_MATERIA_H__

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria {
protected:
  std::string _type;

public:
  AMateria(std::string const &type);
  virtual ~AMateria() {}

  std::string const &getType() const; // Returns the materia type

  virtual AMateria *clone() const = 0;
  virtual void      use(ICharacter &target);
};

#endif