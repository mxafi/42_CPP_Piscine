#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << dog->getType() << " says ";
  dog->makeSound();

  std::cout << cat->getType() << " says ";
  cat->makeSound();

  std::cout << meta->getType() << " says ";
  meta->makeSound();

  return 0;
}
