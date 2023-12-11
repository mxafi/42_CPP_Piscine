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
  {
    std::cout << "------ brain ex01 example test ------" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
  }
  {
    std::cout << "------ brain ex01 mandatory test ------" << std::endl;

    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++) {
      delete animals[i];
    }
  }
  {
    std::cout << "------ brain ex01 deep copy test ------" << std::endl;

    Cat cat0;
    Dog dog0;

    cat0.setIdea(0, "I am the original cat idea.");
    dog0.setIdea(0, "I am the original dog idea.");

    std::cout << "** cat0 ideas before copy **" << std::endl;
    cat0.printFirst3Ideas();
    std::cout << "** dog0 ideas before copy **" << std::endl;
    dog0.printFirst3Ideas();

    Cat cat1(cat0);
    Dog dog1(dog0);

    cat0.setIdea(1, "I am the original cats second idea. (after copy)");
    dog0.setIdea(1, "I am the original dogs second idea. (after copy)");

    std::cout << "** cat0 ideas after copy and adding a second idea **" << std::endl;
    cat0.printFirst3Ideas();
    std::cout << "** dog0 ideas after copy and adding a second idea **" << std::endl;
    dog0.printFirst3Ideas();

    std::cout << "** cat1 ideas after copy and new cat0 idea **" << std::endl;
    cat1.printFirst3Ideas();
    std::cout << "** dog1 ideas after copy and new dog0 idea **" << std::endl;
    dog1.printFirst3Ideas();

    cat1.setIdea(1, "I am the new cats second idea.");
    dog1.setIdea(1, "I am the new dogs second idea.");

    std::cout << "** cat1 ideas after new cat1 idea **" << std::endl;
    cat1.printFirst3Ideas();
    std::cout << "** dog1 ideas after new dog1 idea **" << std::endl;
    dog1.printFirst3Ideas();

    std::cout << "** cat0 ideas after new cat1 idea **" << std::endl;
    cat0.printFirst3Ideas();
    std::cout << "** dog0 ideas after new dog1 idea **" << std::endl;
    dog0.printFirst3Ideas();
  }
  return 0;
}
