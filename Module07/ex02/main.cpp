#include <cassert>
#include <iostream>
#include <exception>
#include "Array.hpp"

int main() {
  // Construction with no parameter: Creates an empty array.
  Array<int> emptyArray;
  assert(emptyArray.size() == 0);

  // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
  Array<int> array(5);
  assert(array.size() == 5);
  array[0] = 42;
  array[1] = 21;
  array[2] = 84;
  assert(array[0] == 42);
  assert(array[1] == 21);
  assert(array[2] == 84);

  // Construction by copy and assignment operator.
  Array<int> copyArray(array);
  assert(copyArray.size() == array.size());
  assert(copyArray[0] == 42);
  assert(copyArray[1] == 21);
  assert(copyArray[2] == 84);

  Array<int> assignedArray;
  assignedArray = array;
  assert(assignedArray.size() == array.size());
  assert(assignedArray[0] == 42);
  assert(assignedArray[1] == 21);
  assert(assignedArray[2] == 84);

  // Modifying the original array should not affect the copy or assigned array
  array[0] = 10;
  assert(copyArray[0] != array[0]);
  assert(assignedArray[0] != array[0]);

  // Elements can be accessed through the subscript operator: [ ]
  assert(array[0] == 10);

  // When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
  try {
    int value = array[10];
    // The above line should throw an exception, so the following line should not be executed.
    (void)value;  // Avoid unused variable warning
    std::cout << "This line should not be printed." << std::endl;
  } catch (const std::exception& e) {
    std::cout << "OK Exception caught: " << e.what() << std::endl;
  }

  // A member function size() that returns the number of elements in the array.
  assert(array.size() == 5);

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
