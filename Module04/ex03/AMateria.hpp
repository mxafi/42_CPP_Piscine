#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
 private:
  AMateria();
  std::string type;

 protected:
  AMateria(const AMateria& other);

 public:
  AMateria(const std::string& type);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& other);

  const std::string& getType() const;

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif