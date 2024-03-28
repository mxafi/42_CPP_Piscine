#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  AForm* createPresidentialPardonForm(std::string target);
  AForm* createRobotomyRequestForm(std::string target);
  AForm* createShrubberyCreationForm(std::string target);

 public:
  ~Intern();
  Intern();
  Intern(Intern& other);
  Intern& operator=(Intern& other);

  AForm* makeForm(std::string name, std::string target);

  class NoSuchFormException : public std::runtime_error {
   public:
    NoSuchFormException(std::string& msg) : std::runtime_error(msg){};
    NoSuchFormException(const char* msg) : std::runtime_error(msg){};
  };
};

#endif
