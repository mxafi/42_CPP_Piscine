#include "PmergeMe.hpp"

template std::vector<int> PmergeMe::_sort(const std::vector<int>& container);
template std::deque<int> PmergeMe::_sort(const std::deque<int>& container);

template bool PmergeMe::_isSorted(const std::vector<int>& container);
template bool PmergeMe::_isSorted(const std::deque<int>& container);

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() : _isLoaded(false) {}

PmergeMe::PmergeMe(PmergeMe& other) {
  _inputVec = other._inputVec;
  _inputDeq = other._inputDeq;
  _isLoaded = other._isLoaded;
  _vecSortTimeUs = other._vecSortTimeUs;
  _deqSortTimeUs = other._deqSortTimeUs;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other) {
  if (this != &other) {
    _inputVec = other._inputVec;
    _inputDeq = other._inputDeq;
    _isLoaded = other._isLoaded;
    _vecSortTimeUs = other._vecSortTimeUs;
    _deqSortTimeUs = other._deqSortTimeUs;
  }
  return *this;
}

void PmergeMe::reset() {
  _inputVec.clear();
  _inputDeq.clear();
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
    _inputVec.push_back(num);
    _inputDeq.push_back(num);
  }
  _isLoaded = true;
}

void PmergeMe::run() {
  if (!_isLoaded) {
    throw std::runtime_error("no data loaded");
  }

  if (_isSorted(_inputVec)) {
    throw std::runtime_error("input is already sorted");
  }

  std::cout << YELLOW << "Before: ";
  for (int i : _inputVec) {
    std::cout << i << " ";
  }
  std::cout << RESET << std::endl;

  std::chrono::steady_clock::time_point vecStart = std::chrono::high_resolution_clock::now();
  std::vector<int> sortedVec = _sort(_inputVec);
  std::chrono::steady_clock::time_point vecStop = std::chrono::high_resolution_clock::now();
  _vecSortTimeUs = std::chrono::duration<double, std::micro>(vecStop - vecStart).count();

  std::chrono::steady_clock::time_point deqStart = std::chrono::high_resolution_clock::now();
  std::deque<int> sortedDeq = _sort(_inputDeq);
  std::chrono::steady_clock::time_point deqStop = std::chrono::high_resolution_clock::now();
  _deqSortTimeUs = std::chrono::duration<double, std::micro>(deqStop - deqStart).count();

  if (_inputVec.size() != sortedVec.size() || sortedVec.size() != sortedDeq.size()) {
    throw std::runtime_error("vector and deque sizes do not match after sorting");
  }
  for (size_t i = 0; i < sortedVec.size(); i++) {
    if (sortedVec[i] != sortedDeq[i]) {
      throw std::runtime_error("vector and deque elements do not match after sorting");
    }
  }
  bool vecSorted = _isSorted(sortedVec);
  if (!vecSorted)
    std::cout << MAGENTA << "Warning: vec not sorted" << RESET << std::endl;
  bool deqSorted = _isSorted(sortedDeq);
  if (!deqSorted)
    std::cout << MAGENTA << "Warning: deq not sorted" << RESET << std::endl;

  std::cout << YELLOW << "After : ";
  for (int i : sortedVec) {
    std::cout << i << " ";
  }
  std::cout << RESET << std::endl;

  std::cout << YELLOW << "Time to sort " << std::setw(7) << _inputVec.size() << " elements with vector: " << std::setw(10) << _vecSortTimeUs
            << " μs" << RESET << std::endl;

  std::cout << YELLOW << "Time to sort " << std::setw(7) << _inputDeq.size() << " elements with  deque: " << std::setw(10) << _deqSortTimeUs
            << " μs" << RESET << std::endl;
}

template <typename T>
T PmergeMe::_sort(const T& container) {
  bool isOdd = container.size() % 2;
  std::cout << "isOdd: " << isOdd << std::endl;
  size_t half_n = container.size() / 2;
  std::cout << "half_n: " << half_n << std::endl;

  if (container.size() < 2) {
    return container;
  }
  return container;
}

template <typename T>
bool PmergeMe::_isSorted(const T& container) {
  if (container.size() < 2) {
    return true;
  }
  for (size_t i = 0; i < container.size() - 1; i++) {
    if (container[i] > container[i + 1]) {
      return false;
    }
  }
  return true;
}
