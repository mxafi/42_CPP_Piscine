#ifndef CHARACTER_HPP
#define CHARACTER_HPP

//#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
 public:
  Character(std::string name);
  ~Character();
  Character(const Character& other);
  Character& operator=(const Character& other);

  const std::string& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

 private:
  Character();
  std::string name;
  AMateria* inventory[4];
  AMateria* pile[100];
};

#endif
