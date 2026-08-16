#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
 public:
  explicit Animal();
  Animal(const Animal& animal);
  Animal& operator=(const Animal& animal);
  ~Animal();
  virtual void makeSound();

 protected:
  std::string type_;
};

#endif
