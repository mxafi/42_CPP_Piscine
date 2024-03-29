#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException(
        "Bureaucrat::GradeTooHighException from constructor");
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException(
        "Bureaucrat::GradeTooLowException from constructor");
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
  this->grade = other.grade;
  return *this;
}

std::string Bureaucrat::getName(void) {
  return this->name;
}

unsigned int Bureaucrat::getGrade(void) {
  return this->grade;
}

void Bureaucrat::incrementGrade(void) {
  if (grade == 1)
    throw Bureaucrat::GradeTooHighException(
        "Bureaucrat::GradeTooHighException from incrementGrade");
  grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (grade == 150)
    throw Bureaucrat::GradeTooLowException(
        "Bureaucrat::GradeTooLowException from decrementGrade");
  grade++;
}

void Bureaucrat::signForm(Form& form) {
  if (form.getSignature() == true) {
    std::cout << name << " couldn't sign " << form.getName()
              << " because it has already been signed." << std::endl;
    return;
  }
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << "." << std::endl;
  } catch (Form::GradeTooLowException& e) {
    std::cout << name << " couldn't sign " << form.getName()
              << " because his grade is not high enough." << std::endl;
  }
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
      << ".";
  return out;
}
