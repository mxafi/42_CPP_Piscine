#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "BureaucratException.hpp"

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
  static BureaucratException GradeTooHighException(void);
  static BureaucratException GradeTooLowException(void);
};
std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif
