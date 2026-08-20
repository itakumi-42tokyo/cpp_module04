#include "Ice.h"

#include <iostream>

#include "ICharacter.h"

Ice::Ice() : AMateria("ice") {
  // std::cout << "Ice: default constructor called." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.getType()) {
  // std::cout << "Ice: copy construtor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
  std::cout << "Ice: operator= called." << std::endl;
  (void)other;
  return *this;
}

Ice::~Ice() {
  // std::cout << "Ice: destructor called." << std::endl;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
             << std::endl;
}
