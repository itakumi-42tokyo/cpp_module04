#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal() {
  this->type_ = "WrongCat";
  std::cout << "WrongCat: default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal(cat) {
  this->type_ = cat.type_;
  std::cout << "WrongCat: copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cat) {
  setType(cat.type_);
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat: destructor called." << std::endl;
}

void WrongCat::makeSound() {
  std::cout << "WrongCat Sound Gyao~~ Gyao~~" << std::endl;
}

void WrongCat::setType(std::string type) { this->type_ = type; }

std::string WrongCat::getType() { return this->type_; }
