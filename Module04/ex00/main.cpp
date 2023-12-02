#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* animal = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << dog->getType() << " says ";
  dog->makeSound();

  std::cout << cat->getType() << " says ";
  cat->makeSound();

  std::cout << animal->getType() << " says ";
  animal->makeSound();

  std::cout << wrongCat->getType() << " says ";
  wrongCat->makeSound();

  return 0;
}
