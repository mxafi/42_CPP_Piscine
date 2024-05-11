#include <iostream>

#include "RPN.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
    return 1;
  }
  try {
    RPN rpn(av[1]);
    int result = rpn.getResult();
    std::cout << result << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
