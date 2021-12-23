#include "Character.hpp"

Character::Character() {
  _name = "Anonymous";
  initializeInventory();
  initializeCreated();
  _equipNum = 0;
  _createdNum = 0;
}

Character::Character(const std::string &name) {
  _name = name;
  initializeInventory();
  initializeCreated();
  _equipNum = 0;
  _createdNum = 0;
}

Character::Character(const Character &other) { *this = other; }

Character &Character::operator=(const Character &other) {
  _name = other._name;
  clearInventory();
  clearCreated();
  initializeInventory();
  initializeCreated();
  for (int i = 0; i < 4; i++) {
    if (other._inventory[i]) {
      _inventory[i] = other._inventory[i]->clone();
      _created[i] = _inventory[i];
    }
  }
  _equipNum = other._equipNum;
  _createdNum = other._equipNum;
  return *this;
}

Character::~Character() { clearCreated(); }

void Character::initializeInventory() {
  for (int i = 0; i < 4; i++) {
    _inventory[i] = NULL;
  }
}

void Character::initializeCreated() {
  for (int i = 0; i < 16; i++) {
    _created[i] = NULL;
  }
}

void Character::clearInventory(void) {
  for (int i = 0; i < 4; i++) {
    delete _inventory[i];
  }
  _equipNum = 0;
}

void Character::clearCreated(void) {
  for (int i = 0; i < 16; i++) {
    delete _created[i];
  }
  _createdNum = 0;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (!m) {
    std::cout << "[ Error ] Materia is NULL!" << std::endl;
    return;
  }
  if (_equipNum == 4) {
    std::cout << "[ Error ] Full Inventory!" << std::endl;
    return;
  }
  if (_createdNum == 16) {
    clearCreated();
    initializeCreated();
    _createdNum = _equipNum;
    for (unsigned int i = 0; i < _equipNum; i++) {
      _created[i] = _inventory[i];
    }
  }
  for (int i = 0; i < 4; i++) {
    if (!_inventory[i]) {
      _inventory[i] = m;
      break;
    }
  }
  _equipNum++;
  _created[_createdNum++] = m;
}

void Character::unequip(int idx) {
  if (idx > 3 || idx < 0) {
    std::cout << "[ Error ] " << idx << ": Access Error!" << std::endl;
    return;
  }
  if (_equipNum == 0) {
    std::cout << "[ Error ] No Materia!" << std::endl;
    return;
  }
  if (_inventory[idx])
    _equipNum--;
  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx > 3 || idx < 0) {
    std::cout << "[ Error ] " << idx << ": Access Error!" << std::endl;
    return;
  }
  if (_inventory[idx])
    _inventory[idx]->use(target);
  else
    std::cout << "[ Error ] " << idx << ": Access Error" << std::endl;
}
