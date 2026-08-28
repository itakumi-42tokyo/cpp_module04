#include "Cure.h"

#include <iostream>

#include "ICharacter.h"

Cure::Cure() : AMateria("cure") {
  // std::cout << "Cure: default constructor called." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.getType()) {
  // std::cout << "Cure: copy constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
  std::cout << "Cure: operator= called." << std::endl;
  (void)other;
  return *this;
}

Cure::~Cure() {
  // std::cout << "Cure: destructor called." << std::endl;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
