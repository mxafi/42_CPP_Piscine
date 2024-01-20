#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name(name), grade(grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
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
    throw Bureaucrat::GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (grade == 150)
    throw Bureaucrat::GradeTooLowException();
  grade++;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
  std::cout << bureaucrat.getName() << ", bureaucrat grade "
            << bureaucrat.getGrade() << ".";
  return out;
}

BureaucratException Bureaucrat::GradeTooHighException(void) {
  return BureaucratException("Bureaucrat::GradeTooHighException");
}

BureaucratException Bureaucrat::GradeTooLowException(void) {
  return BureaucratException("Bureaucrat::GradeTooLowException");
}
