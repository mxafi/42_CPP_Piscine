#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

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
  int shortestSpan();
  int longestSpan();

 private:
  Span();
  std::vector<int> _span;
  unsigned int _size;
};

#endif
