#include <cstdlib>
#include <iostream>

#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main() {
  // test1 can you override?
  std::cout << "--- Test1 ---" << std::endl;
  Cat tama;
  Dog poti;
  tama.makeSound();
  poti.makeSound();

  // test2
  std::cout << "--- Test2 ---" << std::endl;
  WrongCat tiger;
  WrongAnimal human;
  tiger.makeSound();
  human.makeSound();

  // test3
  std::cout << "--- Test3 ---" << std::endl;
  WrongAnimal beetle;
  WrongCat stag_beetle;
  beetle = stag_beetle;
  beetle.makeSound();

  WrongAnimal* bee = new WrongCat;
  bee->makeSound();
  WrongCat* envolved_bee = static_cast<WrongCat*>(bee);
  envolved_bee->makeSound();
  delete bee;

  std::cout << "--- end ---" << std::endl;
  return EXIT_SUCCESS;
}
