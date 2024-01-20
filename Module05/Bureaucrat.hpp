#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
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
  BureaucratException GradeTooHighException(void);
  BureaucratException GradeTooLowException(void);
};

#endif
