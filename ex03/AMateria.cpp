#include "AMateria.h"

#include <iostream>

AMateria::AMateria(std::string const& type) : type_(type) {
  // std::cout << "AMateria: default constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) : type_(other.type_) {
  // std::cout << "AMateria: copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
  // std::cout << "AMateria: operator= called." << std::endl;
  // Because the type is const, the function doesn't subsitute other's type.
  (void)other;
  return *this;
}

AMateria::~AMateria() {
  // std::cout << "AMateria:: destructor called." << std::endl;
}

std::string const& AMateria::getType() const { return this->type_; }

void AMateria::use(ICharacter& target) { (void)target; }
