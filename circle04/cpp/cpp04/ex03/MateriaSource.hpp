#ifndef _MATERIA_SOURCE_H__
#define _MATERIA_SOURCE_H__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *   _materiaStorage[4];
  unsigned int _materiaStorageNum;

	void initializeStorage(void);
	void clearStorage(void);

public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  virtual ~MateriaSource();

  virtual void      learnMateria(AMateria *);
  virtual AMateria *createMateria(std::string const &type);
};

#endif