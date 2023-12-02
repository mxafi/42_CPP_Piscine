#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
  std::cout << "Animal has been constructed. (default)" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
  std::cout << "Animal has been constructed. (copy)" << std::endl;
}

Animal::~Animal(void) {
  std::cout << "Animal has been destructed." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  this->type = other.type;
  std::cout << "Animal has been assigned." << std::endl;
  return *this;
}

void Animal::makeSound(void) const {
  std::cout << "Animal makes an unspecified animal sound..." << std::endl;
}

std::string Animal::getType(void) const {
  return this->type;
}
