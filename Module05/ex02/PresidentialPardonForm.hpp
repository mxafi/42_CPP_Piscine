#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  PresidentialPardonForm();
  std::string target_;

 public:
  ~PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(PresidentialPardonForm& other);
  void execute(Bureaucrat const& executor) const;
};

#endif
