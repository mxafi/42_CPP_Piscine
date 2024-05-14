#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "color.h"

class PmergeMe {
 private:
  std::vector<int> _testVec;
  std::deque<int> _testDeq;

  bool _isLoaded;

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
