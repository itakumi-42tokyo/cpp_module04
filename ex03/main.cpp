#include <cassert>
#include <cstdlib>
#include <iostream>

#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

namespace {
void runSubjectTest() {
  std::cout << "------- Subject Test Case -----------" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::string name = "me";
  ICharacter* me = new Character(name);
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  std::cout << "----------------------------" << std::endl;
}

// AMateria::clone() produces an independent instance with the same type.
void testMateriaClone() {
  Ice ice;
  Cure cure;

  assert(ice.getType() == "ice");
  assert(cure.getType() == "cure");

  AMateria* ice_clone = ice.clone();
  AMateria* cure_clone = cure.clone();
  assert(ice_clone != NULL && ice_clone != &ice);
  assert(cure_clone != NULL && cure_clone != &cure);
  assert(ice_clone->getType() == "ice");
  assert(cure_clone->getType() == "cure");
  delete ice_clone;
  delete cure_clone;

  std::cout << "OK: AMateria clone" << std::endl;
}

// equip() must ignore NULL and must ignore materias past the 4-slot capacity
// without touching the ones already equipped.
void testCharacterEquip() {
  Character hero("hero");
  Character target("target");

  hero.equip(NULL);
  hero.equip(new Ice());
  hero.equip(new Cure());
  hero.equip(new Ice());
  hero.equip(new Cure());

  AMateria* overflow = new Ice();
  hero.equip(overflow);  // slots already full: must be a no-op
  hero.use(0, target);   // still the first Ice, unaffected by the rejection
  delete overflow;        // ownership was never taken since it was rejected

  std::cout << "OK: Character equip (NULL/overflow ignored)" << std::endl;
}

// unequip() must ignore out-of-range indices and must clear the slot
// (without deleting it: ownership reverts to whoever still holds the
// pointer) so a later equip() into the same slot works.
void testCharacterUnequip() {
  Character hero("hero");
  Character target("target");

  hero.unequip(-1);  // no-op, must not crash
  hero.unequip(4);   // no-op, must not crash

  AMateria* ice = new Ice();
  hero.equip(ice);
  hero.unequip(0);
  hero.use(0, target);  // slot is now empty: must be a no-op, no crash
  delete ice;            // caller regains responsibility after unequip

  hero.equip(new Cure());  // slot 0 must be reusable after unequip
  hero.use(0, target);

  std::cout << "OK: Character unequip (range + slot reuse)" << std::endl;
}

// use() must ignore an out-of-range index and an empty slot, and must
// dispatch to the equipped materia's use() otherwise.
void testCharacterUse() {
  Character hero("hero");
  Character target("target");

  hero.use(-1, target);  // no-op
  hero.use(4, target);   // no-op
  hero.use(0, target);   // no materia equipped yet: no-op

  hero.equip(new Ice());
  hero.use(0, target);  // "* shoots an ice bolt at target *"

  std::cout << "OK: Character use (range + empty slot)" << std::endl;
}

// The copy constructor must deep-copy equipped materias: unequipping on the
// original must not affect the copy.
void testCharacterCopyConstructor() {
  Character target("target");
  Character original("original");
  AMateria* ice = new Ice();
  original.equip(ice);

  Character copy(original);
  original.unequip(0);
  copy.use(0, target);  // still works: copy owns its own clone

  delete ice;  // original no longer references it after unequip

  std::cout << "OK: Character copy constructor (deep copy)" << std::endl;
}

// operator= must survive self-assignment, must release the previously
// equipped materias, and must deep-copy the source's materias.
void testCharacterAssignmentOperator() {
  Character target("target");
  Character a("a");
  Character b("b");

  AMateria* ice = new Ice();
  a.equip(ice);
  b.equip(new Cure());

  a = a;         // self-assignment must not crash or double free
  a.use(0, target);

  b = a;          // b's Cure must be released, replaced by a deep copy of a's Ice
  b.use(0, target);

  a.unequip(0);   // must not affect b's independent copy
  b.use(0, target);
  delete ice;      // caller regains responsibility after unequip

  std::cout << "OK: Character operator= (self-assign + deep copy)"
            << std::endl;
}

// learnMateria() must ignore NULL and must ignore samples past the 4-slot
// capacity. createMateria() must return NULL for an unknown type and a
// fresh clone for a known one.
void testMateriaSourceLearnAndCreate() {
  MateriaSource src;

  src.learnMateria(NULL);
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());

  AMateria* overflow = new Ice();
  src.learnMateria(overflow);  // sample slots already full: must be a no-op
  delete overflow;              // ownership was never taken since it was rejected

  AMateria* unknown = src.createMateria("fire");
  assert(unknown == NULL);

  AMateria* ice = src.createMateria("ice");
  assert(ice != NULL);
  delete ice;

  std::cout << "OK: MateriaSource learnMateria/createMateria" << std::endl;
}

// Regression test: copying/assigning a MateriaSource that has fewer than 4
// samples learned must not read past materias_count_ into uninitialized
// slots (this used to delete/clone garbage pointers and crash).
void testMateriaSourceCopyWithPartialSlots() {
  MateriaSource src;
  src.learnMateria(new Ice());  // only 1 of 4 slots filled

  MateriaSource copied(src);
  AMateria* m = copied.createMateria("ice");
  assert(m != NULL);
  delete m;

  MateriaSource assigned;
  assigned = src;
  m = assigned.createMateria("ice");
  assert(m != NULL);
  delete m;

  src = src;  // self-assignment must not crash or double free
  m = src.createMateria("ice");
  assert(m != NULL);
  delete m;

  std::cout << "OK: MateriaSource copy/assign with partial slots"
            << std::endl;
}

// operator= must release the target's previously learned samples before
// deep-copying the source's ones.
void testMateriaSourceAssignReplacesExisting() {
  MateriaSource a;
  a.learnMateria(new Ice());

  MateriaSource b;
  b.learnMateria(new Cure());

  b = a;
  assert(b.createMateria("cure") == NULL);  // old sample is gone

  AMateria* m = b.createMateria("ice");
  assert(m != NULL);
  delete m;

  std::cout << "OK: MateriaSource operator= replaces existing samples"
            << std::endl;
}

void runMyTest() {
  std::cout << "------- My Test Cases -----------" << std::endl;
  testMateriaClone();
  testCharacterEquip();
  testCharacterUnequip();
  testCharacterUse();
  testCharacterCopyConstructor();
  testCharacterAssignmentOperator();
  testMateriaSourceLearnAndCreate();
  testMateriaSourceCopyWithPartialSlots();
  testMateriaSourceAssignReplacesExisting();
  std::cout << "----------------------------" << std::endl;
}
}  // namespace

int main() {
  runSubjectTest();
  runMyTest();
  return EXIT_SUCCESS;
}
