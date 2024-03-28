#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5), target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
    : AForm(other), target_(other.target_) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm& other) {
  target_ = other.target_;
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: gradeToExecute");
  if (getSignature() == false)
    throw AForm::FormNotSignedException(
        "AForm::FormNotSignedException: getSignature");

  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
