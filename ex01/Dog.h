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
  std::string getType() const;
  void setType(std::string type);
  Brain* brain_;
};

#endif
