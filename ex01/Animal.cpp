#include "Animal.h"

Animal::Animal() : type_("Animal!") {
  std::cout << "Animal: constructor called." << std::endl;
}

Animal::Animal(const Animal& animal) : type_(animal.type_) {
  std::cout << "Animal: copy constructor called." << std::endl;
}

// we should use copy and swap.
Animal& Animal::operator=(const Animal& a) {
  this->type_ = a.type_;
  return *this;
}

Animal::~Animal() { std::cout << "Animal: destructor called." << std::endl; }

void Animal::makeSound() const { std::cout << "Animal Sound!!" << std::endl; }

std::string Animal::getType() const { return type_; }

void Animal::setType(const std::string& type) { type_ = type; }
