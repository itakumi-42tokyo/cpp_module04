#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
 public:
  explicit Cat();
  Cat(const Cat& cat);
  Cat& operator=(const Cat& other);
  ~Cat();
  void makeSound() const;

 private:
  Brain* brain_;
};

#endif
