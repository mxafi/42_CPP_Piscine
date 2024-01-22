#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form() {}

Form::Form(std::string name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : name(name),
      isSigned(false),
      requiredGradeToSign(gradeToSign),
      requiredGradeToExecute(gradeToExecute) {
  if (gradeToSign > 150)
    throw Form::GradeTooLowException("Form::GradeTooLowException: gradeToSign");
  if (gradeToSign < 1)
    throw Form::GradeTooHighException(
        "Form::GradeTooHighException: gradeToSign");
  if (gradeToExecute > 150)
    throw Form::GradeTooLowException(
        "Form::GradeTooLowException: gradeToExecute");
  if (gradeToExecute < 1)
    throw Form::GradeTooHighException(
        "Form::GradeTooHighException: gradeToExecute");
}

Form::Form(Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      requiredGradeToSign(other.requiredGradeToSign),
      requiredGradeToExecute(other.requiredGradeToExecute) {}

Form& Form::operator=(Form& other) {
  isSigned = other.isSigned;
  return *this;
}

const std::string& Form::getName() {
  return name;
}

bool Form::getSignature() {
  return isSigned;
}

unsigned int Form::getGradeToSign() {
  return requiredGradeToSign;
}

unsigned int Form::getGradeToExecute() {
  return requiredGradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > requiredGradeToSign)
    throw Form::GradeTooLowException(
        "Form::GradeTooLowException: bureaucrat.getGrade");
  isSigned = true;
}

std::ostream& operator<<(std::ostream& out, Form& form) {
  std::cout << form.getName() << ", form signing/execution grades "
            << form.getGradeToSign() << "/" << form.getGradeToExecute()
            << ", isSigned: " << form.getSignature() << ".";
  return out;
}
