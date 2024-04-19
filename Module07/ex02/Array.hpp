#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <class T>
class Array {
 public:
  ~Array();
  Array();
  Array(unsigned int n);
  Array(Array& other);
  Array& operator=(Array& other);
  T& operator[](unsigned int index);
  unsigned int size() const;

 private:
  unsigned int _size;
  T* _array;
};

#include "Array.tpp"

#endif
