#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
 public:
  explicit Dog();
  Dog(const Dog& dog);
  Dog& operator=(const Dog& dog);
  ~Dog();
  void makeSound() const;

 private:
  Brain* brain_;
};

#endif
