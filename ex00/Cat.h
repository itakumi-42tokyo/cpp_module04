#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
 public:
  explicit Cat();
  Cat(const Cat& cat);
  Cat& operator=(const Cat& cat);
  ~Cat();
  void makeSound() const;

 private:
  std::string getType() const;
  void setType(std::string type);
};

#endif
