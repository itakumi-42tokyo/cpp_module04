#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

namespace {

void runSubjectTest() {
  std::cout << "------- Subject Test Case -----------" << std::endl;
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();  // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  WrongAnimal* wrong_meta = new WrongAnimal();
  WrongCat* wrong_j = new WrongCat();
  wrong_j->makeSound();
  wrong_meta->makeSound();

  delete wrong_meta;
  delete wrong_j;
  std::cout << "----------------------------" << std::endl;
}

// getType() must reflect the concrete subclass even when accessed through
// a base Animal*, because it just reads the type_ member that Dog/Cat set
// in their own constructors.
void testGetTypeThroughBasePointer() {
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  const Animal* animal = new Animal();

  assert(dog->getType() == "Dog");
  assert(cat->getType() == "Cat");
  assert(animal->getType() != "Dog" && animal->getType() != "Cat");

  delete dog;
  delete cat;
  delete animal;

  std::cout << "OK: getType through Animal*" << std::endl;
}

// makeSound() must be virtual: calling it through an Animal* must run the
// override of the object's real (dynamic) type, never Animal's own body.
void testMakeSoundIsPolymorphic() {
  const int animal_count = 4;
  Animal* animals[animal_count];
  animals[0] = new Dog();
  animals[1] = new Cat();
  animals[2] = new Dog();
  animals[3] = new Cat();

  for (int i = 0; i < animal_count; i++) {
    animals[i]->makeSound();  // Dog/Cat sound, never "Animal Sound!!"
  }
  for (int i = 0; i < animal_count; i++) {
    delete animals[i];
  }

  std::cout << "OK: makeSound is polymorphic through Animal*" << std::endl;
}

// The copy constructor and operator= must leave type_ intact, and
// self-assignment (routed through a pointer so clang's
// -Wself-assign-overloaded doesn't flag the literal `x = x`) must not crash.
void testCopyAndSelfAssign() {
  Dog dog_original;
  Dog dog_copy(dog_original);
  assert(dog_copy.getType() == "Dog");

  Dog* dog_self = &dog_copy;
  dog_copy = *dog_self;
  assert(dog_copy.getType() == "Dog");

  Cat cat_original;
  Cat cat_copy = cat_original;
  assert(cat_copy.getType() == "Cat");

  Cat* cat_self = &cat_copy;
  cat_copy = *cat_self;
  assert(cat_copy.getType() == "Cat");

  std::cout << "OK: Dog/Cat copy constructor + self-assignment" << std::endl;
}

// WrongAnimal::makeSound() is deliberately NOT virtual: calling it through a
// WrongAnimal* pointing at a WrongCat must run WrongAnimal's own sound.
// getType() is unaffected because it just returns the shared type_ data
// member, regardless of which overload's body executes.
void testWrongAnimalNonPolymorphicDispatch() {
  WrongAnimal* animal_ptr = new WrongCat();

  assert(animal_ptr->getType() == "WrongCat");
  animal_ptr->makeSound();  // "WrongAnimal Sound!!" -- the "wrong" behavior

  delete animal_ptr;

  std::cout << "OK: WrongAnimal/WrongCat non-polymorphic makeSound dispatch"
            << std::endl;
}

void runMyTest() {
  std::cout << "------- My Test Cases -----------" << std::endl;
  testGetTypeThroughBasePointer();
  testMakeSoundIsPolymorphic();
  testCopyAndSelfAssign();
  testWrongAnimalNonPolymorphicDispatch();
  std::cout << "----------------------------" << std::endl;
}

}  // namespace

int main() {
  runSubjectTest();
  runMyTest();
  return EXIT_SUCCESS;
}
