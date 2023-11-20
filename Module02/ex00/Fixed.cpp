#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->fixedPointNumberValue_ = 0;
}

Fixed::Fixed(const Fixed& original) {
  std::cout << "Copy constructor called" << std::endl;
  this->fixedPointNumberValue_ = original.fixedPointNumberValue_;
}

Fixed& Fixed::operator=(const Fixed& original) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &original) {
    this->fixedPointNumberValue_ = original.fixedPointNumberValue_;
  }
  return *this;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPointNumberValue_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->fixedPointNumberValue_ = raw;
}
