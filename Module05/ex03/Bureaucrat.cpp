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

std::string Bureaucrat::getName(void) const {
  return this->name;
}

unsigned int Bureaucrat::getGrade(void) const {
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

void Bureaucrat::signForm(AForm& form) {
  if (form.getSignature() == true) {
    std::cout << name << " couldn't sign " << form.getName()
              << " because it has already been signed." << std::endl;
    return;
  }
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << "." << std::endl;
  } catch (AForm::GradeTooLowException& e) {
    std::cout << name << " couldn't sign " << form.getName()
              << " because his grade is not high enough." << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) {
  try {
    form.execute(*this);
    std::cout << name << " executed " << form.getName() << "." << std::endl;
  } catch (AForm::GradeTooLowException& e) {
    std::cout << name << " couldn't execute " << form.getName()
              << " because his grade is not high enough." << std::endl;
  } catch (AForm::FormNotSignedException& e) {
    std::cout << name << " couldn't execute " << form.getName()
              << " because the form is not signed." << std::endl;
  } catch (std::runtime_error& e) {
    std::cout << name << " couldn't execute " << form.getName()
              << " because a runtime error occurred." << std::endl;
  }
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
  std::cout << bureaucrat.getName() << ", bureaucrat grade "
            << bureaucrat.getGrade() << ".";
  return out;
}
