#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

int main() {
  {
    std::cout << "------ Bureaucrat tests ------" << std::endl;
    try {
      std::cout << "try Bureaucrat too high ------" << std::endl;
      Bureaucrat b("Bob", 0);
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat just right ------" << std::endl;
      Bureaucrat b("Bob", 50);
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat too low ------" << std::endl;
      Bureaucrat b("Bob", 151);
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
