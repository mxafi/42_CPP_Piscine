#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
 public:
  ~MateriaSource();
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  MateriaSource& operator=(const MateriaSource& other);
  void learnMateria(AMateria* m);
  AMateria* createMateria(const std::string& type);

 private:
  AMateria* inventory[4];
};

#endif
