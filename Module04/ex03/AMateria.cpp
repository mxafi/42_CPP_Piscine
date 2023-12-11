#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
  this->type = other.type;
  return *this;
}

const std::string& AMateria::getType() const {
  return this->type;
}

void AMateria::use(ICharacter& target) {}
