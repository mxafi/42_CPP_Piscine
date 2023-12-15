#include "Character.hpp"

Character::Character(std::string name) : name(name) {
  for (int i = 0; i < 100; i++) {
    this->pile[i] = NULL;
  }
  for (int i = 0; i < 4; i++) {
    this->inventory[i] = NULL;
  }
}

Character::~Character() {
  for (int i = 0; i < 100; i++) {
    delete this->pile[i];
  }
  for (int i = 0; i < 4; i++) {
    delete this->inventory[i];
  }
}

Character::Character(const Character& other) : name(other.name) {
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]) {
      delete this->inventory[i];
      this->inventory[i] = NULL;
    }
    if (other.inventory[i]) {
      this->inventory[i] = other.inventory[i]->clone();
    }
  }
}

Character& Character::operator=(const Character& other) {
  this->name = other.name;
  for (int i = 0; i < 4; i++) {
    if (this->inventory[i]) {
      delete this->inventory[i];
      this->inventory[i] = NULL;
    }
    if (other.inventory[i]) {
      this->inventory[i] = other.inventory[i]->clone();
    }
  }
  return *this;
}

const std::string& Character::getName() const {
  return this->name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {

  if (idx < 0 || idx > 3 || !inventory[idx])
    return;
  for (int i = 0; i < 100; i++) {
    if (!pile[i]) {
      pile[i] = inventory[idx];
      inventory[idx] = NULL;
      break;
    }
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3 || !inventory[idx])
    return;
  inventory[idx]->use(target);
}