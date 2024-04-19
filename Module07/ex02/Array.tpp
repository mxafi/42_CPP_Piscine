#include "Array.hpp"

template <class T>
Array<T>::~Array() {
  delete[] _array;
}

template <class T>
Array<T>::Array() : _size(0), _array(NULL) {}

template <class T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {}

template <class T>
Array<T>::Array(Array<T>& other) : _size(other._size), _array(new T[other._size]) {
  for (unsigned int i = 0; i < _size; i++) {
    _array[i] = other._array[i];
  }
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>& other) {
  if (this != &other) {
    delete[] _array;
    _size = other._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = other._array[i];
    }
  }
  return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= _size) {
    throw std::out_of_range(
        "exception: Array<T>::operator[]: index out of range");
  }
  return _array[index];
}

template <class T>
unsigned int Array<T>::size() const {
  return _size;
}
