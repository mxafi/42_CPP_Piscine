#include <cassert>
#include <climits>
#include <iostream>
#include <random>
#include <vector>
#include "Span.hpp"

int main() {
  {
    std::cout << "====== example test ======" << std::endl;
    Span span(5);
    try {
      span.addNumber(6);
      span.addNumber(3);
      span.addNumber(17);
      span.addNumber(9);
      span.addNumber(11);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "longest span: " << span.longestSpan() << std::endl;
    assert(span.shortestSpan() == 2);
    assert(span.longestSpan() == 14);
  }
  {
    std::cout << "====== overadd test ======" << std::endl;
    Span span(5);
    try {
      span.addNumber(6);
      span.addNumber(3);
      span.addNumber(17);
      span.addNumber(9);
      span.addNumber(11);
      span.addNumber(11);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== empty shortest span test ======" << std::endl;
    Span span(5);
    try {
      std::cout << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== empty longest span test ======" << std::endl;
    Span span(5);
    try {
      std::cout << span.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== one number shortest span test ======" << std::endl;
    Span span(5);
    span.addNumber(5);
    try {
      std::cout << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== one number longest span test ======" << std::endl;
    Span span(5);
    span.addNumber(5);
    try {
      std::cout << span.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== same number test ======" << std::endl;
    Span span(5);
    span.addNumber(5);
    span.addNumber(5);
    span.addNumber(5);
    span.addNumber(5);
    span.addNumber(5);
    std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "longest span: " << span.longestSpan() << std::endl;
    assert(span.shortestSpan() == 0);
    assert(span.longestSpan() == 0);
  }
  {
    std::cout << "====== add range test ======" << std::endl;
    std::vector<int> generatedValues;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);
    Span span(5);

    for (int i = 0; i < 5; ++i) {
      generatedValues.push_back(dis(gen));
      std::cout << generatedValues[i] << " ";
    }
    std::cout << std::endl;

    span.addNumber(generatedValues.begin(), generatedValues.end());
    std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "longest span: " << span.longestSpan() << std::endl;
  }
  {
    std::cout << "====== overadd range test ======" << std::endl;
    std::vector<int> generatedValues;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);
    Span span(5);

    for (int i = 0; i < 6; ++i) {
      generatedValues.push_back(dis(gen));
      std::cout << generatedValues[i] << " ";
    }
    std::cout << std::endl;

    try {
      span.addNumber(generatedValues.begin(), generatedValues.end());
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "longest span: " << span.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "====== 100 000 numbers test ======" << std::endl;
    std::vector<int> generatedValues;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(INT_MIN, INT_MAX);
    Span span(100000);

    for (int i = 0; i < 100000; ++i) {
      generatedValues.push_back(dis(gen));
    }

    span.addNumber(generatedValues.begin(), generatedValues.end());
    std::cout << "shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "longest span: " << span.longestSpan() << std::endl;
  }
  {
    std::cout << "====== overflow test ======" << std::endl;
    Span span(2);
    span.addNumber(INT_MAX);
    span.addNumber(INT_MIN);
    try {
      std::cout << "shortest span: " << span.shortestSpan() << std::endl;
      std::cout << "longest span: " << span.longestSpan() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    long long distance_between_int_max_and_int_min =
        static_cast<long long>(INT_MAX) - static_cast<long long>(INT_MIN);
    std::cout << "distance between INT_MAX and INT_MIN: "
              << distance_between_int_max_and_int_min << std::endl;
    assert(span.shortestSpan() == distance_between_int_max_and_int_min);
    assert(span.longestSpan() == distance_between_int_max_and_int_min);
  }
  return 0;
}
