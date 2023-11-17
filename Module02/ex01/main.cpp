#include "Fixed.hpp"
#include <iostream>

int main(void)
{
  Fixed a(55.50f);

  float testOutFloat = a.toFloat();
  int   testOutInt = a.toInt();

  std::cout << a.getRawBits() << std::endl;
  std::cout << testOutFloat << std::endl;
  std::cout << testOutInt << std::endl;
  return 0;
}
