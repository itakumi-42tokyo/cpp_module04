#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
 public:
  explicit WrongCat();
  WrongCat(const WrongCat& cat);
  WrongCat& operator=(const WrongCat& cat);
  ~WrongCat();
  void makeSound();
  void setType(std::string type);
  std::string getType();
};

#endif
