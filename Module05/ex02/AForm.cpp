#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm() {}

AForm::AForm(std::string name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : name(name),
      isSigned(false),
      requiredGradeToSign(gradeToSign),
      requiredGradeToExecute(gradeToExecute) {
  if (gradeToSign > 150)
    throw AForm::GradeTooLowException("AForm::GradeTooLowException: gradeToSign");
  if (gradeToSign < 1)
    throw AForm::GradeTooHighException(
        "AForm::GradeTooHighException: gradeToSign");
  if (gradeToExecute > 150)
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: gradeToExecute");
  if (gradeToExecute < 1)
    throw AForm::GradeTooHighException(
        "AForm::GradeTooHighException: gradeToExecute");
}

AForm::AForm(AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      requiredGradeToSign(other.requiredGradeToSign),
      requiredGradeToExecute(other.requiredGradeToExecute) {}

AForm& AForm::operator=(AForm& other) {
  isSigned = other.isSigned;
  return *this;
}

const std::string& AForm::getName() {
  return name;
}

bool AForm::getSignature() {
  return isSigned;
}

unsigned int AForm::getGradeToSign() {
  return requiredGradeToSign;
}

unsigned int AForm::getGradeToExecute() {
  return requiredGradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > requiredGradeToSign)
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: bureaucrat.getGrade");
  isSigned = true;
}

std::ostream& operator<<(std::ostream& out, AForm& AForm) {
  std::cout << AForm.getName() << ", AForm signing/execution grades "
            << AForm.getGradeToSign() << "/" << AForm.getGradeToExecute()
            << ", isSigned: " << AForm.getSignature() << ".";
  return out;
}
