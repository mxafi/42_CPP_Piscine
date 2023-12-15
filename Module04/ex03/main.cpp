#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;

  tmp = src->createMateria("ice");
  me->equip(tmp);
  delete tmp;
  tmp = src->createMateria("cure");
  me->equip(tmp);
  delete tmp;
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  Character originalCharacter("Original");
  tmp = src->createMateria("ice");
  originalCharacter.equip(tmp);
  delete tmp;
  Character copyCharacter(originalCharacter);
  originalCharacter.use(0, *bob);
  copyCharacter.use(0, *bob);

  tmp = src->createMateria("ice");
  me->equip(tmp);
  delete tmp;
  tmp = src->createMateria("cure");
  me->equip(tmp);
  delete tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);
  me->use(4, *bob);

  me->unequip(0);
  me->use(0, *bob);
  me->unequip(1);
  me->use(1, *bob);
  me->unequip(2);
  me->use(2, *bob);
  me->unequip(3);
  me->use(3, *bob);
  me->unequip(4);

  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());
  src->learnMateria(new Ice());

  delete bob;
  delete me;
  delete src;

  return 0;
}