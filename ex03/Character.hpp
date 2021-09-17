#ifndef _CHARACTER_H__
#define _CHARACTER_H__

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string  _name;
  AMateria *   _inventory[4];
  AMateria *   _created[16];
  unsigned int _equipNum;
  unsigned int _createdNum;

  void initializeInventory(void);
  void initializeCreated(void);
  void clearInventory(void);
  void clearCreated(void);

public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  virtual ~Character();

  virtual std::string const &getName() const;

  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif