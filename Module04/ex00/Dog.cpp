#include "Dog.hpp"

Dog::Dog(void) : Animal() {
  this->type = "Dog";
  std::cout << "Dog has been constructed. (default)" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "Dog has been constructed. (copy)" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "Dog has been destructed." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  this->type = other.type;
  std::cout << "Dog has been assigned." << std::endl;
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "Woof." << std::endl;
}
