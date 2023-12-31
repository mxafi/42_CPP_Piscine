#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int fixedPointNumberValue_;
  static const int numberOfFractionalBits_ = 8;

 public:
  // default constructor that initializes the fixed-point number value to 0
  Fixed(void);
  // copy constructor
  Fixed(const Fixed& original);
  // copy assignment operator overload (could just call the copy constructor)
  Fixed& operator=(const Fixed& original);
  // destructor
  ~Fixed(void);
  // returns the raw value of the fixed-point value
  int getRawBits(void) const;
  // sets the raw value of the fixed-point number
  void setRawBits(int const raw);
};

#endif
