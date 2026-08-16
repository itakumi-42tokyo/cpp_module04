#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
 public:
  explicit WrongAnimal();
  WrongAnimal(const WrongAnimal& animal);
  WrongAnimal& operator=(const WrongAnimal& animal);
  ~WrongAnimal();
  void makeSound();
  void setType(std::string type);
  std::string getType();

 protected:
  std::string type_;
};

#endif
