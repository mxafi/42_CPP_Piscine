#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() : _isLoaded(false) {}

PmergeMe::PmergeMe(PmergeMe& other) {
  _testVec = other._testVec;
  _testDeq = other._testDeq;
  _isLoaded = other._isLoaded;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other) {
  if (this != &other) {
    _testVec = other._testVec;
    _testDeq = other._testDeq;
    _isLoaded = other._isLoaded;
  }
  return *this;
}

void PmergeMe::reset() {
  _testVec.clear();
  _testDeq.clear();
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
}