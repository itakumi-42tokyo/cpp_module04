#include <cstdlib>
#include <iostream>

#include "Cat.h"
#include "Dog.h"

int main() {
  Cat tama;
  Dog poti;

  // test1 can you override?
  tama.makeSound();
  poti.makeSound();
  std::cout << "Shoma!!" << std::endl;

  // test2
  return EXIT_SUCCESS;
}
