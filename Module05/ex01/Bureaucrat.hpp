#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Form.hpp"
class Form;

class Bureaucrat {
 private:
  const std::string name;
  unsigned int grade;
  Bureaucrat(void){};

 public:
  Bureaucrat(std::string name, unsigned int grade);
  Bureaucrat(Bureaucrat& other);
  ~Bureaucrat(void);
  Bureaucrat& operator=(Bureaucrat& other);
  std::string getName(void);
  unsigned int getGrade(void);
  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form& form);

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

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif
