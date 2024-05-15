#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "color.h"

class PmergeMe {
 private:
  std::vector<int> _inputVec;
  std::deque<int> _inputDeq;

  bool _isLoaded;
  double _vecSortTimeUs;
  double _deqSortTimeUs;

  template <typename T>
  T _sort(const T& container);

  template <typename T>
  bool _isSorted(const T& container);

  template <typename T>
  void _sortLarge(T& pairs, size_t left, size_t right);

  template <typename T, typename P>
  void _sortRest(T& sortedRet, P& pairs, const T& input, bool isOdd);

  template <typename T>
  void _insert(T& dst, int value);

  template <typename Container>
  struct PairContainer;

 public:
  ~PmergeMe();
  PmergeMe();
  PmergeMe(PmergeMe& other);
  PmergeMe& operator=(PmergeMe& other);

  void reset();
  void load(int ac, char** av);
  void run();
};

#endif
