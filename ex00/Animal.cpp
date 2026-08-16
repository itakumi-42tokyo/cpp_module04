#include "Animal.h"

Animal::Animal() : type_("Animal!") {
  std::cout << "Animal: constructor called." << std::endl;
}

Animal::Animal(const Animal& a) : type_(a.type_) {
  std::cout << "Animal: copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& a) {
  this->type_ = a.type_;
  return *this;
}

Animal::~Animal() { std::cout << "Animal: destructor called." << std::endl; }

void Animal::makeSound() const { std::cout << "Animal Sound!!" << std::endl; }
