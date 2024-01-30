#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
 private:
  const std::string name;
  bool isSigned;
  const unsigned int requiredGradeToSign;
  const unsigned int requiredGradeToExecute;
  AForm();

 public:
  ~AForm();
  AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
  AForm(AForm& other);
  AForm& operator=(AForm& other);
  const std::string& getName();
  bool getSignature();
  unsigned int getGradeToSign();
  unsigned int getGradeToExecute();
  void beSigned(Bureaucrat& bureaucrat);
  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::runtime_error {
   public:
    GradeTooHighException(std::string& msg) : std::runtime_error(msg){};
    GradeTooHighException(const char* msg) : std::runtime_error(msg){};
  };

  class GradeTooLowException : public std::runtime_error {
   public:
    GradeTooLowException(std::string& msg) : std::runtime_error(msg){};
    GradeTooLowException(const char* msg) : std::runtime_error(msg){};
  };
};

std::ostream& operator<<(std::ostream& out, AForm& form);

#endif
