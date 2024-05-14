#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() : _isLoaded(false) {}

PmergeMe::PmergeMe(PmergeMe& other) {
  _testVec = other._testVec;
  _testDeq = other._testDeq;
  _isLoaded = other._isLoaded;
  _vecSortTimeUs = other._vecSortTimeUs;
  _deqSortTimeUs = other._deqSortTimeUs;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other) {
  if (this != &other) {
    _testVec = other._testVec;
    _testDeq = other._testDeq;
    _isLoaded = other._isLoaded;
    _vecSortTimeUs = other._vecSortTimeUs;
    _deqSortTimeUs = other._deqSortTimeUs;
  }
  return *this;
}

void PmergeMe::reset() {
  _testVec.clear();
  _testDeq.clear();
  _vecSortTimeUs = 0.0;
  _deqSortTimeUs = 0.0;
  _isLoaded = false;
}

void PmergeMe::load(int ac, char** av) {
  for (int i = 1; i < ac; i++) {
    int num = 0;
    try {
      num = std::stoi(av[i]);
    } catch (std::out_of_range& e) {
      throw std::out_of_range("argument " + std::to_string(i) + " out of range");
    } catch (std::invalid_argument& e) {
      throw std::invalid_argument("argument " + std::to_string(i) + " is not parsable");
    }
    if (num < 0) {
      throw std::out_of_range("argument " + std::to_string(i) + " out of positive int range");
    }
    _testVec.push_back(num);
    _testDeq.push_back(num);
  }
  _isLoaded = true;
}

void PmergeMe::run() {
  if (!_isLoaded) {
    throw std::runtime_error("no data loaded");
  }

  std::cout << YELLOW << "Before: ";
  for (int i : _testVec) {
    std::cout << i << " ";
  }
  std::cout << RESET << std::endl;

  std::chrono::steady_clock::time_point vecStart = std::chrono::high_resolution_clock::now();
  // Sort the vector
  std::chrono::steady_clock::time_point vecStop = std::chrono::high_resolution_clock::now();
  _vecSortTimeUs = std::chrono::duration<double, std::micro>(vecStop - vecStart).count();

  std::chrono::steady_clock::time_point deqStart = std::chrono::high_resolution_clock::now();
  // Sort the deque
  std::chrono::steady_clock::time_point deqStop = std::chrono::high_resolution_clock::now();
  _deqSortTimeUs = std::chrono::duration<double, std::micro>(deqStop - deqStart).count();

  if (_testVec.size() != _testDeq.size()) {
    throw std::runtime_error("vector and deque sizes do not match after sorting");
  }
  for (size_t i = 0; i < _testVec.size(); i++) {
    if (_testVec[i] != _testDeq[i]) {
      throw std::runtime_error("vector and deque elements do not match after sorting");
    }
  }

  std::cout << YELLOW << "After : ";
  for (int i : _testVec) {
    std::cout << i << " ";
  }
  std::cout << RESET << std::endl;

  std::cout << YELLOW << "Time to sort " << std::setw(7) << _testVec.size() << " elements with vector: " << std::setw(10) << _vecSortTimeUs
            << " μs" << RESET << std::endl;

  std::cout << YELLOW << "Time to sort " << std::setw(7) << _testDeq.size() << " elements with  deque: " << std::setw(10) << _deqSortTimeUs
            << " μs" << RESET << std::endl;
}
