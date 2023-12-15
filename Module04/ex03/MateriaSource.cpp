#include "MateriaSource.hpp"

MateriaSource::~MateriaSource() {
  delete[] inventory;
}

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) {
    inventory[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
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

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
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

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < 4; i++) {
    if (inventory[i] && inventory[i]->getType() == type) {
      return inventory[i]->clone();
    }
  }
  return NULL;
}
