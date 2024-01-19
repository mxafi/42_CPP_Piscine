#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main() {
  {
    std::cout << "------ Bureaucrat tests ------" << std::endl;
    try {
      Bureaucrat b("Bob", 151);
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
