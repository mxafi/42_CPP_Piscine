#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog(void);
  Dog(const Dog& other);
  ~Dog(void);
  Dog& operator=(const Dog& other);
  void makeSound(void) const;
  void setIdea(int index, std::string idea);
  void printFirst3Ideas(void);

 private:
  Brain* brain;
};

#endif
