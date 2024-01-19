#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

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
  std::exception& GradeTooHighException(std::string& message);
  std::exception& GradeTooLowException(std::string& message);
};

#endif
