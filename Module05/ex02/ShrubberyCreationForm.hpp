#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();
  std::string target;

 public:
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(std::string& target);
  ShrubberyCreationForm(ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
  void execute(Bureaucrat const& executor) const;
};

#endif
