#include "Cat.h"

Cat::Cat() {
  this->type_ = "Cat";
  std::cout << "Cat: constructor called." << std::endl;
}

Cat::Cat(const Cat& c) : Animal(c) {
  std::cout << "Cat: copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
  this->type_ = c.type_;
  return *this;
}

Cat::~Cat() { std::cout << "Cat: destructor called." << std::endl; }

void Cat::makeSound() const { std::cout << "Mya~~~ O~~~" << std::endl; }

std::string Cat::getType() const { return type_; }

void Cat::setType(std::string type) { this->type_ = type; }
