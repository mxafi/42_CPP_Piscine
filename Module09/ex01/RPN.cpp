#include "RPN.hpp"

RPN::~RPN() {}

RPN::RPN() : _gotResult(false) {}

RPN::RPN(const RPN& other) {
  *this = other;
}

RPN& RPN::operator=(const RPN& other) {
  _stack = other._stack;
  _gotResult = other._gotResult;
  _result = other._result;
  return *this;
}

RPN::RPN(const std::string& expression) : _gotResult(false) {

  if (expression.empty()) {
    throw std::invalid_argument("empty expression");
  }

  if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
    throw std::invalid_argument("invalid character in expression");
  }

  std::regex r("[0-9] [0-9]( [0-9+/*-])*");
  if (!std::regex_match(expression, r)) {
    throw std::invalid_argument("invalid expression format");
  }

  int operands = 0;
  int operators = 0;
  for (char c : expression) {
    if (c >= '0' && c <= '9') {
      operands++;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      operators++;
    }
  }
  if (operands != operators + 1) {
    throw std::invalid_argument("invalid expression, imbalance between operands and operators");
  }

  for (char c : expression) {
    if (c == ' ') {
      continue;
    } else if (c >= '0' && c <= '9') {
      _stack.push(c - '0');
    } else if (c == '+') {
      if (_stack.size() < 2) {
        throw std::invalid_argument("not enough operands for +");
      }
      int a = _stack.top();
      _stack.pop();
      int b = _stack.top();
      _stack.pop();
      _stack.push(a + b);
    } else if (c == '-') {
      if (_stack.size() < 2) {
        throw std::invalid_argument("not enough operands for -");
      }
      int a = _stack.top();
      _stack.pop();
      int b = _stack.top();
      _stack.pop();
      _stack.push(b - a);
    } else if (c == '*') {
      if (_stack.size() < 2) {
        throw std::invalid_argument("not enough operands for *");
      }
      int a = _stack.top();
      _stack.pop();
      int b = _stack.top();
      _stack.pop();
      _stack.push(a * b);
    } else if (c == '/') {
      if (_stack.size() < 2) {
        throw std::invalid_argument("not enough operands for /");
      }
      int a = _stack.top();
      _stack.pop();
      int b = _stack.top();
      _stack.pop();
      _stack.push(b / a);
    } else {
      throw std::invalid_argument("invalid character in expression, failsafe");
    }
  }
  _result = _stack.top();
  _stack.pop();
  if (!_stack.empty()) {
    throw std::invalid_argument("too many operands, not enough operators, stack not empty");
  }
  _gotResult = true;
}

int RPN::getResult() const {
  if (!_gotResult) {
    throw std::invalid_argument("no result");
  }
  return _result;
}
