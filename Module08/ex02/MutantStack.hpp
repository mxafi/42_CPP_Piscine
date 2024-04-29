#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  ~MutantStack();
  MutantStack();
  MutantStack(MutantStack& other);
  MutantStack& operator=(MutantStack& other);
  typedef typename std::stack<T>::container_type::iterator iterator;
  iterator begin();
  iterator end();
};

#include "MutantStack.tpp"

#endif
