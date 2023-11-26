#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(void);
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& other);
  ~ClapTrap();
  ClapTrap& operator=(const ClapTrap& other);
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string name_;
  int hitPoints_;
  int energyPoints_;
  int attackDamage_;
};

#endif
