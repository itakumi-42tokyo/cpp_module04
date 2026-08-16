#include "Dog.h"

Dog::Dog() {
  this->type_ = "Dog";
  std::cout << "Dog: constructor called." << std::endl;
}

Dog::Dog(const Dog& c) : Animal(c) {
  std::cout << "Dog: copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& c) {
  this->type_ = c.type_;
  return *this;
}

Dog::~Dog() { std::cout << " Dog: destructor called." << std::endl; }

void Dog::makeSound() const { std::cout << "Waon! Waon!" << std::endl; }

std::string Dog::getType() const { return type_; }

void Dog::setType(std::string type) { this->type_ = type; }
