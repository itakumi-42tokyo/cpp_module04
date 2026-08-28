#include "Dog.h"

Dog::Dog() {
  this->setType("Dog");
  std::cout << "Dog: constructor called." << std::endl;
}

Dog::Dog(const Dog& c) : Animal(c) {
  std::cout << "Dog: copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& c) {
  this->setType(c.getType());
  return *this;
}

Dog::~Dog() { std::cout << "Dog: destructor called." << std::endl; }

void Dog::makeSound() const { std::cout << "Waon! Waon!" << std::endl; }
