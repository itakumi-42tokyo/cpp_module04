#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

class Character : public ICharacter {
 public:
  explicit Character(const std::string& name);
  Character(const Character& other);
  Character& operator=(const Character& other);
  ~Character();
  virtual std::string const& getName() const;
  virtual void equip(AMateria* a_materia);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

 private:
  std::string name_;
  static const int slot_num_ = 4;
  AMateria* slot_[slot_num_];
  int slot_count_;
};

#endif
