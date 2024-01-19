#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw std::out_of_range("Bureaucrat::GradeTooHighException");
  else if (grade > 150)
    throw std::out_of_range("Bureaucrat::GradeTooLowException");
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
