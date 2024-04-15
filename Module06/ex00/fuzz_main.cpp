#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(void) {
  std::string input;
  std::getline(std::cin, input);

  ScalarConverter::convert(input);

  return 0;
}
