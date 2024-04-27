#include "Span.hpp"

Span::~Span() {}

Span::Span(const Span& other) : _size(other._size) {
  _span = other._span;
}

Span& Span::operator=(Span& other) {
  _span = other._span;
  _size = other._size;
  return *this;
}

Span::Span(unsigned int n) : _size(n) {
  _span.resize(n);
}

void Span::addNumber(int n) {
  if (_span.size() == _size) {
    throw std::out_of_range("Span is full");
  }
  _span.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  if (_span.size() + std::distance(begin, end) > _size) {
    throw std::out_of_range("Span is full");
  }
  _span.insert(_span.end(), begin, end);
}

int Span::shortestSpan() {
  if (_span.size() < 2) {
    throw std::runtime_error("Span has less than 2 elements");
  }
  std::sort(_span.begin(), _span.end());
  return 0; // FIXME
}

int Span::longestSpan() {
  if (_span.size() < 2) {
    throw std::runtime_error("Span has less than 2 elements");
  }
  return 0; // FIXME
}

Span::Span() : _size(SPAN_DEFAULT_SIZE) {
  _span.resize(SPAN_DEFAULT_SIZE);
}
