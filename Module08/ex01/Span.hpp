#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

#define SPAN_DEFAULT_SIZE 1000

class Span {
 public:
  ~Span();
  Span(const Span& other);
  Span& operator=(Span& other);
  Span(unsigned int n);
  void addNumber(int n);
  void addNumber(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end);
  unsigned int shortestSpan();
  unsigned int longestSpan();

 private:
  Span();
  std::vector<int> _span;
  unsigned int _size;
};

#endif
