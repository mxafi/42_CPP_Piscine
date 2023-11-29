#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "ScavTrap that remains Anonymoose has been default constructed!"
            << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap " << name << " has appeared! (name constructor)"
            << std::endl;
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "ScavTrap " << this->name_
            << " has popped out of another ScavTrap! (copy constructor)"
            << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name_
            << " has vanished from existance. (destructor)" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  std::cout << "ScavTrap assignment operator overload called!" << std::endl;
  this->name_ = other.name_;
  this->hitPoints_ = other.hitPoints_;
  this->energyPoints_ = other.energyPoints_;
  this->attackDamage_ = other.attackDamage_;

  return *this;
}

void ScavTrap::attack(const std::string& target) {
  if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
    return;

  this->energyPoints_--;
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode."
            << std::endl;
}

void ScavTrap::printValues(void) {
  std::cout << "Printing my values below! Bzzzzzt." << std::endl;
  std::cout << "        name: " << this->name_ << std::endl;
  std::cout << "   hitPoints: " << this->hitPoints_ << std::endl;
  std::cout << "energyPoints: " << this->energyPoints_ << std::endl;
  std::cout << "attackDamage: " << this->attackDamage_ << std::endl;
}
