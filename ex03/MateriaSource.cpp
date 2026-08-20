#include "MateriaSource.h"

#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource(), materias_count_(0U) {
  for (int i = 0; i < materias_num_; i++) {
    sample_materias_[i] = NULL;
  }
  // std::cout << "MateriaSource: default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
    : IMateriaSource(), materias_count_(other.materias_count_) {
  for (int i = 0; i < materias_num_; i++) {
    sample_materias_[i] = other.sample_materias_[i] == NULL
                              ? NULL
                              : other.sample_materias_[i]->clone();
  }
  // std::cout << "MateriaSource: copy constructor called." << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  std::cout << "MateriaSource: operator= called." << std::endl;
  if (this == &other) {
    return *this;
  }
  for (int i = 0; i < materias_num_; i++) {
    delete sample_materias_[i];
    sample_materias_[i] = NULL;
  }
  materias_count_ = other.materias_count_;
  for (int i = 0; i < materias_num_; i++) {
    sample_materias_[i] = other.sample_materias_[i] == NULL
                              ? NULL
                              : other.sample_materias_[i]->clone();
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < materias_count_; i++) {
    delete sample_materias_[i];
  }
  // std::cout << "MateriaSource: destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria* a_materia) {
  if (a_materia == NULL || materias_count_ >= materias_num_) {
    return;
  }
  this->sample_materias_[materias_count_] = a_materia;
  this->materias_count_++;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  size_t idx = findMateria(type);
  if (idx == std::string::npos) {
    return NULL;
  }
  // AMateria
  // という抽象クラスにオブジェクトを作らせることで，動的ディスパッチが自動で判断できる。
  return sample_materias_[idx]->clone();
}

size_t MateriaSource::findMateria(std::string const& type) {
  for (int i = 0; i < materias_count_; i++) {
    if (sample_materias_[i]->getType() == type) {
      return i;
    }
  }
  return std::string::npos;
}
