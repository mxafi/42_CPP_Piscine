#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat(void);
  Cat(const Cat& other);
  ~Cat(void);
  Cat& operator=(const Cat& other);
  void makeSound(void) const;
  void setIdea(int index, std::string idea);
  void printFirst3Ideas(void);

 private:
  Brain* brain;
};

#endif
