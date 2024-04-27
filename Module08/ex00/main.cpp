#include <iostream>
#include <map>
#include <vector>
#include "easyfind.hpp"

int main() {
  std::vector<int> container;
  container.push_back(1);  // 0
  container.push_back(2);  // 1
  container.push_back(3);  // 2
  container.push_back(4);  // 3
  container.push_back(5);  // 4

  int value1 = 3;
  int value2 = 6;

  int result1 = easyfind(container, value1);
  int result2 = easyfind(container, value2);

  std::cout << "Value " << value1 << " found at index: " << result1
            << std::endl;
  std::cout << "Value " << value2 << " found at index: " << result2
            << std::endl;

  return 0;
}
