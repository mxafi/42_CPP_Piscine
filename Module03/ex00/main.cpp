#include "ClapTrap.hpp"

int main(void) {
  ClapTrap a("Andy");
  ClapTrap b("Bobby");
  ClapTrap c;
  ClapTrap d(a);
  c = b;

  a.attack("Bobby");
  b.attack("Andy");
  b.takeDamage(1);
  a.takeDamage(2);
  b.beRepaired(1);
}
