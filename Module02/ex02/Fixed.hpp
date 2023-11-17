#include <iostream>

class Fixed
{
private:
	int fixedPointNumberValue_;
	static const int numberOfFractionalBits_ = 8;

public:
	// default constructor that initializes the fixed-point number value to 0
	Fixed(void);
	// copy constructor
	Fixed(const Fixed &original);
	// const int constructor, fract bits 8 and converts to fixed point
	Fixed(const int intN);
	// const float constructor, frac bits 8 and converts to fixed point
	Fixed(const float floatN);
	// destructor
	~Fixed(void);

	// copy assignment operator overload
	Fixed &operator=(const Fixed &original);

	// comparison overloads (implementation missing)
	bool operator>(const Fixed &right);
	bool operator<(const Fixed &right);
	bool operator>=(const Fixed &right);
	bool operator<=(const Fixed &right);
	bool operator==(const Fixed &right);
	bool operator!=(const Fixed &right);

	// The 4 arithmetic operators: +, -, *, and / (prototypes missing)

	// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement) operators (prototypes missing)

	// returns the raw value of the fixed-point value
	int getRawBits(void) const;
	// sets the raw value of the fixed-point number
	void setRawBits(int const raw);
	// converts the fixed-point value to a floating-point value
	float toFloat(void) const;
	// converts the fixed-point value to an integer value
	int toInt(void) const;

	// min and max functions for Fixed and const Fixed numbers (prototypes missing)
};
// insertion operator overload for Fixed class numbers to insert a float
std::ostream &operator<<(std::ostream &out, const Fixed &fixedNumber);
