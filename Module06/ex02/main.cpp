#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <iostream>
#include <random>
#include <chrono>

Base* generate(void) {
  long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine engine(seed);
  std::uniform_int_distribution<int> distribution(0, 2);
  int random = distribution(engine);

  switch (random) {
    case 0:
      std::cout << "Generate: A" << std::endl;
      return new A();
    case 1:
      std::cout << "Generate: B" << std::endl;
      return new B();
    case 2:
      std::cout << "Generate: C" << std::endl;
      return new C();
    default:
      std::cerr << "Generate: Error: random number out of range" << std::endl;
      return nullptr;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "Identify: A (from pointer)" << std::endl;
    return;
  }
  if (dynamic_cast<B*>(p)) {
    std::cout << "Identify: B (from pointer)" << std::endl;
    return;
  }
  if (dynamic_cast<C*>(p)) {
    std::cout << "Identify: C (from pointer)" << std::endl;
    return;
  }
  std::cerr << "Identify: Error: unknown type (from pointer)" << std::endl;
}

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "Identify: A (from reference)" << std::endl;
    return;
  } catch (std::bad_cast& e) {}
  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    std::cout << "Identify: B (from reference)" << std::endl;
    return;
  } catch (std::bad_cast& e) {}
  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    std::cout << "Identify: C (from reference)" << std::endl;
    return;
  } catch (std::bad_cast& e) {}
  std::cerr << "Identify: Error: unknown type (from reference)" << std::endl;
}

int main(void) {
  std::cout << "** Tester start!" << std::endl;
  for (int i = 1; i <= 5; i++) {
    std::cout << "* test round: " << i << std::endl;
    Base* input = generate();
    identify(input);
    identify(*input);
    delete input;
  }
  std::cout << "** Tester end!" << std::endl;
  return 0;
}
