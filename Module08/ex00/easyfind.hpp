#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

/**
 * @brief Finds the first occurrence of a value in a container.
 * 
 * @tparam T The type of the container.
 * @param container The container to search in.
 * @param value The value to search for.
 * @return int The index of the first occurrence of the value, -1 if not found, -2 if an exception occurs.
 */
template <typename T>
int easyfind(T& container, int value) {
  typename T::iterator it;
  try {
    it = std::find(container.begin(), container.end(), value);
  } catch (std::exception& e) {
    return -2;
  }
  if (it == container.end())
    return -1;
  return std::distance(container.begin(), it);
}

#endif
