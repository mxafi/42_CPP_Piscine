#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& other) {
  return *this;
}

AMateria* Cure::clone() const {
  return new Cure;
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
