#include "Dog.hpp"

Dog::Dog(void) : AAnimal(), brain(new Brain) {
  this->type = "Dog";
  std::cout << "Dog has been constructed. (default)" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog has been constructed. (copy)" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "Dog has been destructed." << std::endl;
  delete this->brain;
}

Dog& Dog::operator=(const Dog& other) {
  this->type = other.type;
  std::cout << "Dog has been assigned." << std::endl;
  delete brain;
  this->brain = new Brain(*other.brain);
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "Woof." << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
  this->brain->setIdea(index, idea);
}

void Dog::printFirst3Ideas(void) {
  this->brain->printIdeas(0, 2);
}
