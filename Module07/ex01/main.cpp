#include <iostream>

#include "iter.hpp"

template <typename T>
void print(T val) {
  std::cout << val << std::endl;
}

template <typename T>
void addOne(T val) {
  val += 1;
  std::cout << val << std::endl;
}

int main() {
  std::cout << "* --- test int" << std::endl;
  {
    int arr[] = {5, 4, 3, 2, 1};
    std::cout << "--- print:" << std::endl;
    iter(arr, 5, print<int>);
    std::cout << "--- addOne:" << std::endl;
    iter(arr, 5, addOne<int>);
  }
  std::cout << "* --- test double" << std::endl;
  {
    double arr[] = {13.11, 23.22, 33.33};
    std::cout << "--- print:" << std::endl;
    iter(arr, 3, print<double>);
    std::cout << "--- addOne:" << std::endl;
    iter(arr, 3, addOne<double>);
  }
  std::cout << "* --- test float" << std::endl;
  {
    float arr[] = {10.25f, 20.25f, 30.25f, 40.25f};
    std::cout << "--- print:" << std::endl;
    iter(arr, 4, print<float>);
    std::cout << "--- addOne:" << std::endl;
    iter(arr, 4, addOne<float>);
  }
  std::cout << "* --- test char" << std::endl;
  {
    char arr[] = {'a', 'b', 'c', 'd'};
    std::cout << "--- print:" << std::endl;
    iter(arr, 4, print<char>);
    std::cout << "--- addOne:" << std::endl;
    iter(arr, 4, addOne<char>);
  }
  return 0;
}