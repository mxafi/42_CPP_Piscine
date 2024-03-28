#include "Intern.hpp"

Intern::~Intern() {}

Intern::Intern() {}

Intern::Intern(Intern& other) {
  (void)other;
}

Intern& Intern::operator=(Intern& other) {
  (void)other;
  return *this;
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};

  AForm* (Intern::*formCreators[3])(std::string) = {
      &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm,
      &Intern::createPresidentialPardonForm};

  for (int i = 0; i < 3; i++) {
    if (name == formNames[i]) {
      AForm* form = (this->*formCreators[i])(target);
      std::cout << "Intern creates " << form->getName() << std::endl;
      return form;
    }
  }

  throw NoSuchFormException(
      std::string("NoSuchFormException: No form found with name: " + name)
          .c_str());
}
