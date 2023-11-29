#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : name_("Anonymoose"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap that remains Anonymoose"
            << " has appeared! (default constructor)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap " << this->name_ << " has appeared! (name constructor)"
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_),
      hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_),
      attackDamage_(other.attackDamage_) {
  std::cout << "ClapTrap " << this->name_
            << " has popped out of another ClapTrap! (copy constructor)"
            << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name_
            << " has vanished from existance. (destructor)" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  std::cout << "ClapTrap " << this->name_
            << " has been overtaken by the body and soul of another ClapTrap "
            << other.name_ << "! (assignment operator overload)" << std::endl;
  this->name_ = other.name_;
  this->hitPoints_ = other.hitPoints_;
  this->energyPoints_ = other.energyPoints_;
  this->attackDamage_ = other.attackDamage_;

  return *this;
}

void ClapTrap::attack(const std::string& target) {
  if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
    return;

  this->energyPoints_--;
  std::cout << "ClapTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints_ == 0)
    return;

  if (this->hitPoints_ <= static_cast<long>(amount)) {
    this->hitPoints_ = 0;
    std::cout << "ClapTrap " << this->name_ << " has taken " << amount
              << " points of damage and now is dead with 0 hit points!"
              << std::endl;
    return;
  }

  this->hitPoints_ -= amount;
  std::cout << "ClapTrap " << this->name_ << " has taken " << amount
            << " points of damage and now has " << this->hitPoints_
            << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints_ <= 0 || this->energyPoints_ <= 0)
    return;

  this->energyPoints_--;
  this->hitPoints_ += amount;
  std::cout << "ClapTrap " << this->name_ << " has been repaired for " << amount
            << " points and now has a total of " << this->hitPoints_
            << " hit points!" << std::endl;
}
