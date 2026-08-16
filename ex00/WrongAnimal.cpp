#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type_("WrongAnimal!") {
  std::cout << "WrongAnimal: default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& w) : type_(w.type_) {
  std::cout << "WrongAnimal: copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& w) {
  this->type_ = w.type_;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal: destructor called." << std::endl;
}

void WrongAnimal::makeSound() {
  std::cout << "WrongAnimal Sound!!" << std::endl;
}
