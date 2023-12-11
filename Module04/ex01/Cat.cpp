#include "Cat.hpp"

Cat::Cat(void) : Animal(), brain(new Brain) {
  this->type = "Cat";
  std::cout << "Cat has been constructed. (default)" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Cat has been constructed. (copy)" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "Cat has been destructed." << std::endl;
  delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
  this->type = other.type;
  std::cout << "Cat has been assigned." << std::endl;
  delete brain;
  this->brain = new Brain(*other.brain);
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "Meow." << std::endl;
}

void Cat::setIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}

void Cat::printFirst3Ideas(void) {
  this->brain->printIdeas(0, 2);
}
