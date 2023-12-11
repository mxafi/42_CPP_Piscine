#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

  {
    std::cout << "------ direct access tests (dot) ------" << std::endl;

    Cat cat;
    Dog dog;

    std::cout << cat.getType() << " says ";
    cat.makeSound();
    std::cout << std::endl;

    std::cout << dog.getType() << " says ";
    dog.makeSound();
    std::cout << std::endl;
  }
  {
    std::cout << "------ indirect access tests (pass base reference) ------"
              << std::endl;

    Cat cat;
    Dog dog;

    std::cout << cat.getType() << " says ";
    cat.makeSound();

    std::cout << dog.getType() << " says ";
    dog.makeSound();
  }
  {
    std::cout << "------ brain ex02 deep copy test ------" << std::endl;

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

    std::cout << "** cat0 ideas after copy and adding a second idea **"
              << std::endl;
    cat0.printFirst3Ideas();
    std::cout << "** dog0 ideas after copy and adding a second idea **"
              << std::endl;
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
  { std::cout << "------ ex02 playground ------" << std::endl; }
  return 0;
}
