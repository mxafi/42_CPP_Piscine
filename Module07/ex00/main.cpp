#include <assert.h>
#include <iostream>
#include <string>

#include "whatever.hpp"

int main(void) {
  std::cout << "==== START TESTS ============" << std::endl;

  {
    std::cout << "*=== example test ===========" << std::endl;

    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  }

  std::cout << "*=== my tests w/o output ====" << std::endl;

  // a is always greater than b and equal to c
  // so min(a, b) should return b
  // and max(a, b) should return a
  // and min(a, c) should return c
  // and max(a, c) should return c
  {
    int a = 42;
    int b = 21;
    int c = a;

    assert(::min(a, b) == b);
    assert(::max(a, b) == a);
    assert(::min(a, c) == c);
    assert(::max(a, c) == c);
    ::swap(a, b);
    assert(a == 21);
    assert(b == c);
  }
  {
    double a = 42;
    double b = 21;
    double c = a;

    assert(::min(a, b) == b);
    assert(::max(a, b) == a);
    assert(::min(a, c) == c);
    assert(::max(a, c) == c);
    ::swap(a, b);
    assert(a == 21);
    assert(b == c);
  }
  {
    std::string a = "hello world";
    std::string b = "hello back";
    std::string c = a;

    assert(::min(a, b) == b);
    assert(::max(a, b) == a);
    assert(::min(a, c) == c);
    assert(::max(a, c) == c);
    ::swap(a, b);
    assert(a == "hello back");
    assert(b == c);
  }

  std::cout << "==== END TESTS ==============" << std::endl;
}