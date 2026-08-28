#include "Cat.h"

Cat::Cat() {
  this->setType("Cat");
  std::cout << "Cat: constructor called." << std::endl;
}

Cat::Cat(const Cat& c) : Animal(c) {
  std::cout << "Cat: copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
  this->setType(c.getType());
  return *this;
}

Cat::~Cat() { std::cout << "Cat: destructor called." << std::endl; }

void Cat::makeSound() const { std::cout << "Mya~~~ O~~~" << std::endl; }
