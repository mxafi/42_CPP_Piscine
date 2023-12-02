#include "Cat.hpp"

Cat::Cat(void) : Animal() {
  this->type = "Cat";
  std::cout << "Cat has been constructed. (default)" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat has been constructed. (copy)" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "Cat has been destructed." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  this->type = other.type;
  std::cout << "Cat has been assigned." << std::endl;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Meow." << std::endl;
}
