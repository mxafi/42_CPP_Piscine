#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
  return *this;
}

AMateria* Ice::clone() const {
  return new Ice;
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.name << " *" << std::endl;
}
