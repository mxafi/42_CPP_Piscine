#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal") {
  std::cout << "AAnimal has been constructed. (default)" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
  std::cout << "AAnimal has been constructed. (copy)" << std::endl;
}

AAnimal::~AAnimal(void) {
  std::cout << "AAnimal has been destructed." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
  this->type = other.type;
  std::cout << "AAnimal has been assigned." << std::endl;
  return *this;
}

std::string AAnimal::getType(void) const {
  return this->type;
}
