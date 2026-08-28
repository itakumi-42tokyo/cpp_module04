#include "Dog.h"

#include "Brain.h"

Dog::Dog() {
  this->type_ = "Dog";
  this->brain_ = new Brain;
  std::cout << "Dog: constructor called." << std::endl;
}

Dog::Dog(const Dog& cat) : Animal(cat) {
  this->brain_ = new Brain(*cat.brain_);
  std::cout << "Dog: copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  this->type_ = other.type_;
  if (&other != this) {
    delete this->brain_;
    this->brain_ = new Brain(*(other.brain_));
  }
  return *this;
}

Dog::~Dog() {
  delete this->brain_;
  std::cout << "Dog: destructor called." << std::endl;
}

void Dog::makeSound() const { std::cout << "Waon! Waon!" << std::endl; }
