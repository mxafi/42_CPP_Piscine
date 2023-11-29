#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  {
    std::cout << "------ named construction ------" << std::endl;
    ScavTrap nam("Namey");
    nam.printValues();
  }
  {
    std::cout << "------ default construction ------" << std::endl;
    ScavTrap def;
    def.printValues();
  }
  {
    std::cout << "------ copy construction ------" << std::endl;
    ScavTrap original("Originey");
    ScavTrap copy(original);
    copy.printValues();
  }
  {
    std::cout << "------ assignment operator ------" << std::endl;
    ScavTrap original("Originey");
    ScavTrap assigned;
    assigned = original;
    assigned.printValues();
  }
  {
    std::cout << "------ Scav attack ------" << std::endl;
    ScavTrap a("Scavy");
    a.printValues();
    a.attack("an iMac from 2019");
    a.printValues();
  }
  {
    std::cout << "------ Scav guard ------" << std::endl;
    ScavTrap a("Scavy");
    a.guardGate();
  }
  {
    std::cout << "------ Scav takeDamage and beRepaired ------" << std::endl;
    ScavTrap a("Scavy");
    a.printValues();
    a.takeDamage(11);
    a.printValues();
    a.beRepaired(3);
    a.printValues();
  }
}
