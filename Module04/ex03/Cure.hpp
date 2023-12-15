#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
 public:
  Cure();
  ~Cure();
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);

  AMateria* clone() const;
  void use(ICharacter& target);
};

#endif
