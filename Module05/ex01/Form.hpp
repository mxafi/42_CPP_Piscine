#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
 private:
  const std::string name;
  bool isSigned;
  const unsigned int requiredGradeToSign;
  const unsigned int requiredGradeToExecute;
  Form();

 public:
  ~Form();
  Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
  Form(Form& other);
  Form& operator=(Form& other);
  const std::string& getName();
  bool getSignature();
  unsigned int getGradeToSign();
  unsigned int getGradeToExecute();
  void beSigned(Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, Form& form);

#endif
