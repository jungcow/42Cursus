#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  initializeStorage();
  _materiaStorageNum = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  for (int i = 0; i < 4; i++) {
    if (other._materiaStorage[i])
      _materiaStorage[i] = other._materiaStorage[i]->clone();
  }
  _materiaStorageNum = other._materiaStorageNum;
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    delete _materiaStorage[i];
  }
}

void MateriaSource::initializeStorage() {
  for (int i = 0; i < 4; i++) {
    _materiaStorage[i] = NULL;
  }
}

void MateriaSource::clearStorage() {
  for (int i = 0; i < 4; i++) {
    delete _materiaStorage[i];
  }
  _materiaStorageNum = 0;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m) {
    std::cout << "[ Error ] Materia is NULL!" << std::endl;
    return;
  }
  if (_materiaStorageNum == 4) {
    std::cout << "[ Error ] Full Storage!" << std::endl;
    return;
  }
  _materiaStorage[_materiaStorageNum] = m;
  _materiaStorageNum++;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < _materiaStorageNum; i++) {
    if (_materiaStorage[i] && type == _materiaStorage[i]->getType()) {
      return _materiaStorage[i]->clone();
    }
  }
  return NULL;
}