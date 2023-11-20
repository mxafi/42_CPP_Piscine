#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  int fixedPointNumberValue_;
  static const int numberOfFractionalBits_ = 8;

 public:
  Fixed(void);
  Fixed(const Fixed& original);
  Fixed& operator=(const Fixed& original);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);

  // const int constructor, fract bits 8 and converts to fixed point
  Fixed(const int intN);
  // const float constructor, frac bits 8 and converts to fixed point
  Fixed(const float floatN);
  // converts the fixed-point value to a floating-point value
  float toFloat(void) const;
  // converts the fixed-point value to an integer value
  int toInt(void) const;
};

// insertion operator overload for Fixed class numbers to insert a float
std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber);

#endif
