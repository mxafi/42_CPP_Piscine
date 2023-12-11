#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  this->type = "WrongCat";
  std::cout << "WrongCat has been constructed. (default)" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "WrongCat has been constructed. (copy)" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat has been destructed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  this->type = other.type;
  std::cout << "WrongCat has been assigned." << std::endl;
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "WrongMeow." << std::endl;
}
