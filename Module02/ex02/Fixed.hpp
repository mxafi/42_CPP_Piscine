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
  Fixed(const int intN);
  Fixed(const float floatN);
  ~Fixed(void);
  Fixed& operator=(const Fixed& original);

  bool operator>(const Fixed& right);
  bool operator<(const Fixed& right);
  bool operator>=(const Fixed& right);
  bool operator<=(const Fixed& right);
  bool operator==(const Fixed& right);
  bool operator!=(const Fixed& right);

  Fixed operator+(const Fixed& right);
  Fixed operator-(const Fixed& right);
  Fixed operator*(const Fixed& right);
  Fixed operator/(const Fixed& right);

  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  static Fixed& min(Fixed& n1, Fixed& n2);
  static const Fixed& min(const Fixed& n1, const Fixed& n2);
  static Fixed& max(Fixed& n1, Fixed& n2);
  static const Fixed& max(const Fixed& n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber);

#endif
