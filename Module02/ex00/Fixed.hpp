#include <iostream>

class Fixed {
	private:
		int					fixedPointNumberValue_;
		static const int	numberOfFractionalBits_ = 8;
	public:
		// default constructor that initializes the fixed-point number value to 0
		Fixed(void);
		// copy constructor
		Fixed(const Fixed& original);
		// copy assignment operator overload (could just call the copy constructor)
		Fixed& operator = (const Fixed& original);
		// destructor
		~Fixed(void);
		// returns the raw value of the fixed-point value
		int getRawBits(void) const;
		// sets the raw value of the fixed-point number
		void setRawBits(int const raw);
		// const int constructor, fract bits 8 and converts to fixed point
		Fixed(const int intN);
		// const float constructor, frac bits 8 and converts to fixed point
		Fixed(const float fpN);
		// converts the fixed-point value to a floating-point value
		float toFloat(void) const;
		// converts the fixed-point value to an integer value
		int toInt(void) const;
};
// insertion operator overload for Fixed class numbers to insert a float
std::ostream& operator << (std::ostream& out, const Fixed& fixedNumber);
