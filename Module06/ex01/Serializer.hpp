#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

#include "data.h"

class Serializer {
 private:
  Serializer();
  Serializer(const Serializer& other);
  Serializer& operator=(const Serializer& other);

 public:
  ~Serializer();

  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

};

#endif
