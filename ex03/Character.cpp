#include "Character.h"

#include <iostream>

#include "AMateria.h"

Character::Character(const std::string& name)
    : ICharacter(), name_(name), slot_count_(0) {
  for (unsigned int i = 0; i < slot_num_; i++) {
    slot_[i] = NULL;
  }
  // std::cout << "Character: default constructor called." << std::endl;
}

Character::Character(const Character& other)
    : ICharacter(), name_(other.name_), slot_count_(other.slot_count_) {
  for (unsigned int i = 0; i < slot_num_; i++) {
    slot_[i] = (other.slot_[i] == NULL) ? NULL : other.slot_[i]->clone();
  }
  // std::cout << "Character: copy constructor called." << std::endl;
}

Character& Character::operator=(const Character& other) {
  std::cout << "Character: operator= called." << std::endl;
  if (this == &other) {
    return *this;
  }
  name_ = other.name_;
  slot_count_ = other.slot_count_;
  for (int i = 0; i < slot_num_; i++) {
    delete slot_[i];
    slot_[i] = (other.slot_[i] == NULL) ? NULL : other.slot_[i]->clone();
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < slot_num_; i++) {
    delete slot_[i];
  }
  // std::cout << "Character: destructor called." << std::endl;
}

std::string const& Character::getName() const { return this->name_; }

void Character::equip(AMateria* a_materia) {
  if (slot_count_ >= slot_num_ || a_materia == NULL) {
    return;
  }
  slot_[slot_count_] = a_materia;
  slot_count_++;
}

// NOTE
// idxが不正常の場合は何もしない。
// 配列は常にすべて埋まっていると限らない。
// Character::unequipはdelete禁止！？
void Character::unequip(int idx) {
  if (idx < 0 || idx >= slot_num_ || slot_[idx] == NULL) {
    return;
  }
  slot_count_--;
  // 呼び出し元に責任あり。
  slot_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= slot_num_ || slot_[idx] == NULL) {
    return;
  }
  // AMateria::useを使う必要あり。
  slot_[idx]->use(target);
}
