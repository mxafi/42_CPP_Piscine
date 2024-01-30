#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <random>
#include <chrono>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();
  std::string target_;

 public:
  ~RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(RobotomyRequestForm& other);
  void execute(Bureaucrat const& executor) const;
};

#endif
