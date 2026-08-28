#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

// Animal is now abstract (pure virtual destructor + makeSound()). Uncommenting
// the line below must fail to compile -- that failure IS the test for this
// exercise's core requirement, so it can't be expressed as a runtime assert.
// Animal a;

namespace {

void runSubjectTest() {
  std::cout << "------- Subject Test Case -----------" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;  // should not create a leak
  delete i;
  std::cout << "----------------------------" << std::endl;
}

// getType() must reflect the concrete subclass through a base Animal*.
void testGetTypeThroughBasePointer() {
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  assert(dog->getType() == "Dog");
  assert(cat->getType() == "Cat");

  delete dog;
  delete cat;

  std::cout << "OK: getType through Animal*" << std::endl;
}

// The copy constructor must deep-copy the Brain: the copy must keep working
// (and must be independently destructible) after the original is gone.
void testCopyConstructorDeepCopiesBrain() {
  Dog original;
  Dog copy(original);
  assert(copy.getType() == "Dog");
  copy.makeSound();

  Cat cat_original;
  Cat cat_copy = cat_original;  // copy-initialization -> copy constructor
  assert(cat_copy.getType() == "Cat");
  cat_copy.makeSound();

  std::cout << "OK: Dog/Cat copy constructor deep-copies Brain" << std::endl;
}

// Regression test: operator= must allocate its own Brain rather than
// aliasing the source's pointer. Before the fix, `b = a` made a and b share
// one Brain*, and destroying both double-freed it (crash under
// AddressSanitizer). Assigning repeatedly and then letting every object go
// out of scope is the black-box way to catch that regression, since Brain
// itself isn't exposed outside Dog/Cat.
void testAssignmentOperatorDeepCopiesBrain() {
  Dog dog_a;
  Dog dog_b;
  dog_b = dog_a;
  dog_a.makeSound();
  dog_b.makeSound();

  Cat cat_a;
  Cat cat_b;
  cat_b = cat_a;
  cat_a.makeSound();
  cat_b.makeSound();

  std::cout << "OK: Dog/Cat operator= deep-copies Brain" << std::endl;
}

// Self-assignment (routed through a pointer so clang's
// -Wself-assign-overloaded doesn't flag the literal `x = x`) must not crash
// or free the object's own Brain out from under it.
void testSelfAssignment() {
  Dog dog;
  Dog* dog_self = &dog;
  dog = *dog_self;
  dog.makeSound();

  Cat cat;
  Cat* cat_self = &cat;
  cat = *cat_self;
  cat.makeSound();

  std::cout << "OK: Dog/Cat operator= self-assignment safe" << std::endl;
}

// Chained assignment relies on operator= returning a reference to *this.
void testChainedAssignment() {
  Dog a, b, c;
  a = b = c;
  assert(a.getType() == "Dog");
  assert(b.getType() == "Dog");

  std::cout << "OK: Dog operator= supports chained assignment" << std::endl;
}

// Half the array is Dog, half is Cat; every Animal must be deletable
// through its base pointer -- which only works because ~Animal(), though
// pure virtual, still has a body that the derived destructors chain into.
void testMixedArrayDeletedThroughBase() {
  const int animal_count = 4;
  Animal* animals[animal_count];
  animals[0] = new Dog();
  animals[1] = new Dog();
  animals[2] = new Cat();
  animals[3] = new Cat();

  assert(animals[0]->getType() == "Dog");
  assert(animals[1]->getType() == "Dog");
  assert(animals[2]->getType() == "Cat");
  assert(animals[3]->getType() == "Cat");

  for (int i = 0; i < animal_count; i++) {
    delete animals[i];
  }

  std::cout << "OK: mixed Animal* array deleted through base" << std::endl;
}

void runMyTest() {
  std::cout << "------- My Test Cases -----------" << std::endl;
  testGetTypeThroughBasePointer();
  testCopyConstructorDeepCopiesBrain();
  testAssignmentOperatorDeepCopiesBrain();
  testSelfAssignment();
  testChainedAssignment();
  testMixedArrayDeletedThroughBase();
  std::cout << "----------------------------" << std::endl;
}

}  // namespace

int main() {
  runSubjectTest();
  runMyTest();
  return EXIT_SUCCESS;
}
