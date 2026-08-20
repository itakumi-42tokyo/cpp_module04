#include <cstdlib>

#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "ICharacter.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
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
  return EXIT_SUCCESS;
}
