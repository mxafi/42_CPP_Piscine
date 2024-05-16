#include "PmergeMe.hpp"

template std::vector<int> PmergeMe::_sort(const std::vector<int>& container);
template std::deque<int> PmergeMe::_sort(const std::deque<int>& container);

// template void PmergeMe::_sortLarge(std::vector<int>& container, size_t left, size_t right);
// template void PmergeMe::_sortLarge(std::deque<int>& container, size_t left, size_t right);

template bool PmergeMe::_isSorted(const std::vector<int>& container);
template bool PmergeMe::_isSorted(const std::deque<int>& container);

template <typename T, typename Alloc>
struct PmergeMe::PairContainer<std::vector<T, Alloc> > {
  using type = std::vector<std::pair<int, int>, typename Alloc::template rebind<std::pair<int, int> >::other>;
};

template <typename T, typename Alloc>
struct PmergeMe::PairContainer<std::deque<T, Alloc> > {
  using type = std::deque<std::pair<int, int>, typename Alloc::template rebind<std::pair<int, int> >::other>;
};

// static utility functions

template <typename Pair>
static void printPairs(const Pair& container) {
  for (const auto& p : container) {
    std::cout << p.first << "," << p.second << " ";
  }
  std::cout << std::endl;
}

template <typename Pair, typename Container>
static Container unpair(const Pair& pairs) {
  Container container;
  size_t n = pairs.size();
  for (size_t i = 0; i < n; i++) {
    container.push_back(pairs[i].first);
    container.push_back(pairs[i].second);
  }
  return container;
}

template <typename T>
static void printContainer(const T& container) {
  for (int i : container) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

// end of static utility functions

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
  size_t half_n = container.size() / 2;  // excludes the odd case

  if (container.size() < 2) {
    return container;
  }

  // form pairs excluding the odd case, first element of the pair is the larger one
  typename PairContainer<T>::type pairs;
  for (size_t i = 0; i < half_n * 2; i += 2) {
    if (container[i] > container[i + 1]) {
      pairs.push_back(std::make_pair(container[i], container[i + 1]));
    } else {
      pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }
  }

  // sort the larger elements and ensure the smaller element of the pair stays with the larger element
  // e.g. 4, 3, 2, 1 -> 2, 1, 4, 3
  const size_t firstIndex = 0;
  const size_t lastIndex = pairs.size() - 1;
  _sortLarge(pairs, firstIndex, lastIndex);

  // sort the remaining elements
  T sorted;
  _sortRest(sorted, pairs, container, isOdd);

  return sorted;
}

template <typename T>
void PmergeMe::_sortLarge(T& pairs, size_t left, size_t right) {
  // recursively merge sort the pairs of elements by the larger element
  // assumes even number of elements
  // assumes the elements are in pairs, e.g. (1, 2), (3, 4), ...
  // assumes the odd index is the larger element of the pair

  // base case is when the left index is greater than the right index
  if (left >= right) {
    return;
  }

  // find the middle index
  size_t middle = (left + right) / 2;

  // recursively sort the halves
  _sortLarge(pairs, left, middle);
  _sortLarge(pairs, middle + 1, right);

  // merge the halves
  T temp;
  size_t i = left;
  size_t j = middle + 1;
  while (i <= middle && j <= right) {
    if (pairs[i].first <= pairs[j].first) {
      temp.push_back(pairs[i]);
      i++;
    } else {
      temp.push_back(pairs[j]);
      j++;
    }
  }

  // copy the remaining elements
  while (i <= middle) {
    temp.push_back(pairs[i]);
    i++;
  }
  while (j <= right) {
    temp.push_back(pairs[j]);
    j++;
  }

  // copy the sorted elements back to the original container
  for (size_t k = left; k <= right; k++) {
    pairs[k] = temp[k - left];
  }
}

template <typename T, typename P>
void PmergeMe::_sortRest(T& sortedRet, P& pairs, const T& input, bool isOdd) {
  size_t k = pairs.size();

  // first pair is the smallest, and it's second element is the smallest element
  sortedRet.push_back(pairs[0].second);

  // create the main chain from the larger elements
  for (size_t i = 0; i < k; i++) {
    sortedRet.push_back(pairs[i].first);
  }

  // insert elements as per ford-johnson up to k/2
  for (size_t i = 1; i <= (k - 1) / 2; i++) {
    if (i + 1 <= (k - 1) / 2) {
      _insert(sortedRet, pairs[i + 1].second);
      _insert(sortedRet, pairs[i].second);
      i++;
    } else {
      _insert(sortedRet, pairs[i].second);
    }
  }

  // insert the remaining elements right to left, starting from the odd case
  if (isOdd) {
    // take into account the odd case
    _insert(sortedRet, input.back());
  }
  for (size_t i = k - 1; i > (k - 1) / 2; i--) {
    _insert(sortedRet, pairs[i].second);
  }
}

// binary insert
template <typename T>
void PmergeMe::_insert(T& dst, int value) {
  auto it = std::lower_bound(dst.begin(), dst.end(), value);
  dst.insert(it, value);
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
