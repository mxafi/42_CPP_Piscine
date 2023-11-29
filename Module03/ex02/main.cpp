#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  {
    std::cout << "------ named construction ------" << std::endl;
    FragTrap nam("Namey");
    nam.printValues();
  }
  {
    std::cout << "------ default construction ------" << std::endl;
    FragTrap def;
    def.printValues();
  }
  {
    std::cout << "------ copy construction ------" << std::endl;
    FragTrap original("Originey");
    FragTrap copy(original);
    copy.printValues();
  }
  {
    std::cout << "------ assignment operator ------" << std::endl;
    FragTrap original("Originey");
    FragTrap assigned;
    assigned = original;
    assigned.printValues();
  }
  {
    std::cout << "------ Frag attack ------" << std::endl;
    FragTrap a("Fragy");
    a.printValues();
    a.attack("an iMac from 2019");
    a.printValues();
  }
  {
    std::cout << "------ Frag highFives ------" << std::endl;
    FragTrap a("Fragy");
    a.highFivesGuys();
  }
  {
    std::cout << "------ Frag takeDamage and beRepaired ------" << std::endl;
    FragTrap a("Fragy");
    a.printValues();
    a.takeDamage(11);
    a.printValues();
    a.beRepaired(3);
    a.printValues();
  }
}
