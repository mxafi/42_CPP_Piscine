#include <cassert>
#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
  {
    std::cout << "====== example test output (stack) ======" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  {
    std::cout << "====== example test output (list) ======" << std::endl;
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::list<int> s(mstack);
  }
  {
    std::cout << "====== iterator test ======" << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    mstack.push(60);
    mstack.push(70);
    mstack.push(80);
    mstack.push(90);
    mstack.push(100);
    assert(mstack.top() == 100);
    mstack.pop();
    assert(mstack.top() == 90);
    assert(mstack.size() == 9);
    MutantStack<int>::iterator it = mstack.begin();
    assert(*it == 10);
    MutantStack<int>::iterator ite = mstack.end();
    int expected = 10;
    while (it != ite) {
      std::cout << *it << std::endl;
      assert(*it == expected);
      expected += 10;
      ++it;
    }
  }
  {
    std::cout << "====== canonical class form test ======" << std::endl;
    MutantStack<int> originalStack;
    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);

    // Testing copy constructor
    MutantStack<int> copyConstructedStack(originalStack);
    assert(copyConstructedStack.size() == originalStack.size());
    MutantStack<int>::iterator itCopy = copyConstructedStack.begin();
    for (MutantStack<int>::iterator itOrig = originalStack.begin();
         itOrig != originalStack.end(); ++itOrig, ++itCopy) {
      assert(*itOrig == *itCopy);
    }

    // Testing assignment operator
    MutantStack<int> assignedStack;
    assignedStack = originalStack;
    assert(assignedStack.size() == originalStack.size());
    MutantStack<int>::iterator itAssigned = assignedStack.begin();
    for (MutantStack<int>::iterator itOrig = originalStack.begin();
         itOrig != originalStack.end(); ++itOrig, ++itAssigned) {
      assert(*itOrig == *itAssigned);
    }
    originalStack.pop();
    assert(originalStack.top() == 2);
    assert(copyConstructedStack.top() == 3);
    assert(assignedStack.top() == 3);
    std::cout << "deep copy tests passed for both copy constructor and "
                 "assignment operator."
              << std::endl;
  }
  return 0;
}
