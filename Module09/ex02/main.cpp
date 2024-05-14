#include <iostream>
#include <stdexcept>

#include "PmergeMe.hpp"
#include "color.h"

#define ERROR_MSG(source, message) \
  { std::cerr << RED << "Error (" << source << "): " << message << RESET << std::endl; }

int main(int ac, char** av) {
  if (ac < 2) {
    std::cerr << RED << "Usage: " << av[0] << " <space delimited positive integer sequence>" << RESET << std::endl;
    return 1;
  }
  if (ac == 2) {
    ERROR_MSG("input", "single argument is always sorted");
    return 1;
  }
  for (int i = 1; i < ac; i++) {
    if (av[i][0] == '\0') {
      ERROR_MSG("input", "empty argument is not allowed");
      return 1;
    }
  }
  PmergeMe pm;
  try {
    pm.load(ac, av);
  } catch (const std::exception& e) {
    ERROR_MSG("input", e.what());
    return 1;
  }
  try {
    pm.run();
  } catch (const std::exception& e) {
    ERROR_MSG("processing", e.what());
    return 1;
  }
  return 0;
}
