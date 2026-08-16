#include <cstdlib>
#include <iostream>

#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

int main() {
  std::cout << "--- Sample Test ---" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;
  delete i;

  std::cout << "--- Test1 ---" << std::endl;
  Cat tama0;
  Cat tama1(tama0);
  Cat tama2 = tama0;
  tama2 = tama2;
  tama0.makeSound();
  tama1.makeSound();
  tama2.makeSound();
  Dog poti0;
  Dog poti1(poti0);
  Dog poti2 = poti0;
  poti2 = poti2;
  poti0.makeSound();
  poti1.makeSound();
  poti2.makeSound();

  std::cout << "--- Test2 ---" << std::endl;
  const int animal_count = 4;
  Animal* animal[animal_count];
  animal[0] = new Dog;
  animal[1] = new Dog;
  animal[2] = new Cat;
  animal[3] = new Cat;

  delete animal[0];
  delete animal[1];
  delete animal[2];
  delete animal[3];

  // Test2
  return 0;
}
