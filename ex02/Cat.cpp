#include "Cat.h"

#include "Brain.h"

Cat::Cat() {
  this->setType("Cat");
  this->brain_ = new Brain;
  std::cout << "Cat: constructor called." << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
  this->brain_ = new Brain(*cat.brain_);
  std::cout << "Cat: copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  this->setType(other.getType());
  if (&other != this) {
    delete this->brain_;
    this->brain_ = new Brain(*(other.brain_));
  }
  return *this;
}

Cat::~Cat() {
  delete this->brain_;
  std::cout << "Cat: destructor called." << std::endl;
}

void Cat::makeSound() const { std::cout << "Mya~~~ O~~~" << std::endl; }
