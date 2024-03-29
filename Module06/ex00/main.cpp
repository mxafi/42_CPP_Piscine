#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <value_to_convert>" << std::endl;
    return 1;
  }

  ScalarConverter::convert(argv[1]);

  return 0;
}
