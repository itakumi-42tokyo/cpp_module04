#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  ~MateriaSource();
  void learnMateria(AMateria* a_materia);
  AMateria* createMateria(std::string const& type);

 private:
  static const int materias_num_ = 4;
  AMateria* sample_materias_[materias_num_];
  int materias_count_;
  size_t findMateria(std::string const& type);
};

#endif
