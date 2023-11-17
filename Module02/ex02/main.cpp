#include "Fixed.hpp"
#include <iostream>

int main(void)
{
  {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
  }
  {
    Fixed a(1);
    Fixed b(1.999f);
    Fixed c(2.0f);
    Fixed d(2.1f);
    Fixed e(-1);
    Fixed f(-1.1f);
    std::cout << "a is " << a.getRawBits() << std::endl;
    std::cout << "b is " << b.getRawBits() << std::endl;
    std::cout << "c is " << c.getRawBits() << std::endl;
    std::cout << "d is " << d.getRawBits() << std::endl;
    std::cout << "e is " << e.getRawBits() << std::endl;
    std::cout << "f is " << f.getRawBits() << std::endl;
  }
  return 0;
}
