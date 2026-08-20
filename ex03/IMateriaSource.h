#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include <string>

#include "AMateria.h"

class IMateriaSource {
 public:
  virtual ~IMateriaSource();
  virtual void learnMateria(AMateria* a_materia) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif
