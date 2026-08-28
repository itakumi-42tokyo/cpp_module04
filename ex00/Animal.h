#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
 public:
  explicit Animal();
  Animal(const Animal& animal);
  Animal& operator=(const Animal& animal);
  virtual ~Animal();
  virtual void makeSound() const;
  std::string getType() const;

 protected:
  void setType(const std::string& type);

 private:
  std::string type_;
};

#endif
