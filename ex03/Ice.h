#ifndef ICE_H
#define ICE_H

#include <string>

#include "AMateria.h"

class Ice : public AMateria {
 public:
  explicit Ice();
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);
  ~Ice();
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};

#endif
