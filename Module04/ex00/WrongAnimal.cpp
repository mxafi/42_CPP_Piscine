#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  std::cout << "WrongAnimal has been constructed. (default)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
  std::cout << "WrongAnimal has been constructed. (copy)" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal has been destructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  this->type = other.type;
  std::cout << "WrongAnimal has been assigned." << std::endl;
  return *this;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal makes an unspecified animal sound..." << std::endl;
}

std::string WrongAnimal::getType(void) const {
  return this->type;
}
