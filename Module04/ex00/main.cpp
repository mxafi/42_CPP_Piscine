#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalSound(const Animal& animal) {
  animal.makeSound();
}

void testWrongAnimalSound(const WrongAnimal& animal) {
  animal.makeSound();
}

int main() {
  {
    std::cout << "------ indirect access tests (pointer) ------" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongAnimal* wrongAnimal = new WrongAnimal();

    std::cout << dog->getType() << " says ";
    dog->makeSound();

    std::cout << cat->getType() << " says ";
    cat->makeSound();

    std::cout << animal->getType() << " says ";
    animal->makeSound();

    std::cout << wrongCat->getType() << " says ";
    wrongCat->makeSound();

    std::cout << wrongAnimal->getType() << " says ";
    wrongAnimal->makeSound();

    delete animal;
    delete dog;
    delete cat;
    delete wrongCat;
    delete wrongAnimal;
  }
  {
    std::cout << "------ direct access tests (dot) ------" << std::endl;

    Cat cat;
    Dog dog;
    Animal animal;
    WrongCat wrongCat;
    WrongAnimal wrongAnimal;

    std::cout << cat.getType() << " says ";
    testAnimalSound(cat);

    std::cout << dog.getType() << " says ";
    testAnimalSound(dog);

    std::cout << animal.getType() << " says ";
    testAnimalSound(animal);

    std::cout << wrongCat.getType() << " says ";
    testWrongAnimalSound(wrongCat);

    std::cout << wrongAnimal.getType() << " says ";
    testWrongAnimalSound(wrongAnimal);
  }
  {
    std::cout << "------ indirect access tests (pass base reference) ------"
              << std::endl;

    Cat cat;
    Dog dog;
    Animal animal;
    WrongCat wrongCat;
    WrongAnimal wrongAnimal;

    std::cout << cat.getType() << " says ";
    cat.makeSound();

    std::cout << dog.getType() << " says ";
    dog.makeSound();

    std::cout << animal.getType() << " says ";
    animal.makeSound();

    std::cout << wrongCat.getType() << " says ";
    wrongCat.makeSound();

    std::cout << wrongAnimal.getType() << " says ";
    wrongAnimal.makeSound();
  }
  {
    std::cout << "------ example test ------" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
  }
  {
    std::cout << "------ wrong example test ------" << std::endl;

    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
  }
  return 0;
}
