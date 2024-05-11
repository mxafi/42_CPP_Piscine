#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <regex>

class RPN {
 public:
  RPN(const std::string& expression);
  ~RPN();

  int getResult() const;

 private:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);

  std::stack<int> _stack;
  bool _gotResult;
  int _result;
};

#endif
