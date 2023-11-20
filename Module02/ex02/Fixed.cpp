#include "Fixed.hpp"

// constructors and destructor

Fixed::Fixed(void) {
  this->fixedPointNumberValue_ = 0;
}

Fixed::Fixed(const Fixed& original) {
  *this = original;
}

Fixed::Fixed(const int intN) {
  this->fixedPointNumberValue_ = static_cast<int>(
      intN * static_cast<float>(1 << this->numberOfFractionalBits_));
}

Fixed::Fixed(const float floatN) {
  this->fixedPointNumberValue_ = static_cast<int>(
      floatN * static_cast<float>(1 << this->numberOfFractionalBits_) +
      (floatN >= 0 ? 0.5 : -0.5));
}

Fixed::~Fixed(void) {}

// operator overload member functions

Fixed& Fixed::operator=(const Fixed& original) {
  if (this != &original)
    this->fixedPointNumberValue_ = original.fixedPointNumberValue_;
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedNumber) {
  out << fixedNumber.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed& right) {
  if (this->fixedPointNumberValue_ > right.fixedPointNumberValue_)
    return true;
  return false;
}

bool Fixed::operator<(const Fixed& right) {
  if (this->fixedPointNumberValue_ < right.fixedPointNumberValue_)
    return true;
  return false;
}

bool Fixed::operator>=(const Fixed& right) {
  if (this->fixedPointNumberValue_ >= right.fixedPointNumberValue_)
    return true;
  return false;
}

bool Fixed::operator<=(const Fixed& right) {
  if (this->fixedPointNumberValue_ <= right.fixedPointNumberValue_)
    return true;
  return false;
}

bool Fixed::operator==(const Fixed& right) {
  if (this->fixedPointNumberValue_ == right.fixedPointNumberValue_)
    return true;
  return false;
}

bool Fixed::operator!=(const Fixed& right) {
  if (this->fixedPointNumberValue_ != right.fixedPointNumberValue_)
    return true;
  return false;
}

Fixed Fixed::operator+(const Fixed& right) {
  Fixed ret;
  ret.fixedPointNumberValue_ =
      this->fixedPointNumberValue_ + right.fixedPointNumberValue_;
  return ret;
}

Fixed Fixed::operator-(const Fixed& right) {
  Fixed ret;
  ret.fixedPointNumberValue_ =
      this->fixedPointNumberValue_ - right.fixedPointNumberValue_;
  return ret;
}

Fixed Fixed::operator*(const Fixed& right) {
  Fixed ret;
  ret.fixedPointNumberValue_ =
      static_cast<int>((static_cast<int64_t>(this->fixedPointNumberValue_) *
                        static_cast<int64_t>(right.fixedPointNumberValue_)) >>
                       ret.numberOfFractionalBits_);
  return ret;
}

Fixed Fixed::operator/(const Fixed& right) {
  Fixed ret;
  ret.fixedPointNumberValue_ =
      static_cast<int>((static_cast<int64_t>(this->fixedPointNumberValue_)
                        << ret.numberOfFractionalBits_) /
                       static_cast<int64_t>(right.fixedPointNumberValue_));
  return ret;
}

Fixed& Fixed::operator++(void) {
  this->fixedPointNumberValue_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed ret = *this;
  this->fixedPointNumberValue_++;
  return ret;
}

Fixed& Fixed::operator--(void) {
  this->fixedPointNumberValue_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed ret = *this;
  this->fixedPointNumberValue_--;
  return ret;
}

// normal member functions

int Fixed::getRawBits(void) const {
  return this->fixedPointNumberValue_;
}

void Fixed::setRawBits(int const raw) {
  this->fixedPointNumberValue_ = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->fixedPointNumberValue_) /
          static_cast<float>(1 << this->numberOfFractionalBits_));
}

int Fixed::toInt(void) const {
  return static_cast<int>(this->toFloat() + 0.5);
}

// static member functions

Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
  if (n1.fixedPointNumberValue_ < n2.fixedPointNumberValue_)
    return n1;
  return n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
  if (n1.fixedPointNumberValue_ < n2.fixedPointNumberValue_)
    return n1;
  return n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
  if (n1.fixedPointNumberValue_ > n2.fixedPointNumberValue_)
    return n1;
  return n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
  if (n1.fixedPointNumberValue_ > n2.fixedPointNumberValue_)
    return n1;
  return n2;
}
