#ifndef _I_MATERIA_SOURCE_H__
#define _I_MATERIA_SOURCE_H__

#include "AMateria.hpp"

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void      learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif