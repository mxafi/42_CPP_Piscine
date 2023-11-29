#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "FragTrap that remains Anonymoose has been default constructed!"
            << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap " << name << " has appeared! (name constructor)"
            << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap " << this->name_
            << " has popped out of another FragTrap! (copy constructor)"
            << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name_
            << " has vanished from existance. (destructor)" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  std::cout << "FragTrap assignment operator overload called!" << std::endl;
  this->name_ = other.name_;
  this->hitPoints_ = other.hitPoints_;
  this->energyPoints_ = other.energyPoints_;
  this->attackDamage_ = other.attackDamage_;

  return *this;
}

void FragTrap::attack(const std::string& target) {
  if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
    return;

  this->energyPoints_--;
  std::cout << "FragTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << this->name_
            << " requests high fives in a positive manner from everyone around!"
            << std::endl;
}

void FragTrap::printValues(void) {
  std::cout << "Printing my values below! Bzzzzzt." << std::endl;
  std::cout << "        name: " << this->name_ << std::endl;
  std::cout << "   hitPoints: " << this->hitPoints_ << std::endl;
  std::cout << "energyPoints: " << this->energyPoints_ << std::endl;
  std::cout << "attackDamage: " << this->attackDamage_ << std::endl;
}
