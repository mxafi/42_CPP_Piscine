#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm& other) {
  target_ = other.target_;
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: gradeToExecute");
  if (getSignature() == false)
    throw AForm::FormNotSignedException(
        "AForm::FormNotSignedException: getSignature");
  
  std::cout << " * some drilling noises *" << std::endl;

  long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine gen(seed);
  std::uniform_int_distribution<int> dist(0, 1);
  int robotomySuccess = dist(gen);

  if (robotomySuccess)
    std::cout << target_ << " has been robotomized successfully." << std::endl;
  else
    std::cout << "Robotomy failed." << std::endl;
}
