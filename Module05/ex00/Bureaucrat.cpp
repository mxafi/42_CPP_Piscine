#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException("Bureaucrat::GradeTooHighException from constructor");
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException("Bureaucrat::GradeTooLowException from constructor");
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
    throw Bureaucrat::GradeTooHighException("Bureaucrat::GradeTooHighException from incrementGrade");
  grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (grade == 150)
    throw Bureaucrat::GradeTooLowException("Bureaucrat::GradeTooLowException from decrementGrade");
  grade++;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
  std::cout << bureaucrat.getName() << ", bureaucrat grade "
            << bureaucrat.getGrade() << "." << std::endl;
  return out;
}
