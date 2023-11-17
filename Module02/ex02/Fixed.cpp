#include "Fixed.hpp"

// constructors and destructor

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumberValue_ = 0;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::Fixed(const int intN)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumberValue_ = int(intN * float(1 << this->numberOfFractionalBits_));
}

Fixed::Fixed(const float floatN)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumberValue_ = int(floatN * float(1 << this->numberOfFractionalBits_) + (floatN >= 0 ? 0.5 : -0.5));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// overload member functions

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &original)
		this->fixedPointNumberValue_ = original.fixedPointNumberValue_;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber)
{
	out << fixedNumber.toFloat();
	return (out);
}

// normal member functions

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumberValue_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumberValue_ = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->fixedPointNumberValue_) / float(1 << this->numberOfFractionalBits_));
}

int Fixed::toInt(void) const
{
	return (int(this->toFloat() + 0.5));
}