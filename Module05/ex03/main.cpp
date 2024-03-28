#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    std::cout << "------ Bureaucrat tests ------" << std::endl;
    try {
      std::cout << "try Bureaucrat too high ------" << std::endl;
      Bureaucrat b("Bob", 0);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat just right ------" << std::endl;
      Bureaucrat b("Bob", 50);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat too low ------" << std::endl;
      Bureaucrat b("Bob", 151);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat 1 increment ------" << std::endl;
      Bureaucrat b("Bob", 1);
      b.incrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat 150 decrement ------" << std::endl;
      Bureaucrat b("Bob", 150);
      b.decrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "try Bureaucrat 50 grade changes ----" << std::endl;
    Bureaucrat f("Fiver", 50);
    std::cout << f << std::endl;
    std::cout << "increment grade ----" << std::endl;
    f.incrementGrade();
    std::cout << f << std::endl;
    std::cout << "decrement grade two times ----" << std::endl;
    f.decrementGrade();
    f.decrementGrade();
    std::cout << f << std::endl;
    try {
      std::cout << "try Bureaucrat catch GradeTooHighException ------"
                << std::endl;
      Bureaucrat b("Bob", 0);
    } catch (Bureaucrat::GradeTooHighException& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat catch GradeTooLowException ------"
                << std::endl;
      Bureaucrat b("Bob", 151);
    } catch (Bureaucrat::GradeTooLowException& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    {
      std::cout << std::endl
                << "------ ShrubberyCreationForm tests ------" << std::endl;
      std::cout << "* test signing and execution" << std::endl;
      ShrubberyCreationForm f1("beta");
      Bureaucrat b1("Bob", 1);
      std::cout << f1 << std::endl << b1 << std::endl;
      try {
        b1.signForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing AForm: " << e.what()
                  << std::endl;
      }
      std::cout << f1 << std::endl;
      try {
        b1.executeForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while executing AForm: " << e.what()
                  << std::endl;
      }
    }
    {
      std::cout << std::endl
                << "------ RobotomyRequestForm tests ------" << std::endl;
      std::cout << "* test signing and execution" << std::endl;
      RobotomyRequestForm f1("delta");
      Bureaucrat b1("Bob", 1);
      std::cout << f1 << std::endl << b1 << std::endl;
      try {
        b1.signForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing AForm: " << e.what()
                  << std::endl;
      }
      std::cout << f1 << std::endl;
      try {
        b1.executeForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while executing AForm: " << e.what()
                  << std::endl;
      }
    }
    {
      std::cout << std::endl
                << "------ PresidentialPardonForm tests ------" << std::endl;
      std::cout << "* test signing and execution" << std::endl;
      PresidentialPardonForm f1("GuiltyMan");
      Bureaucrat b1("Bob", 1);
      std::cout << f1 << std::endl << b1 << std::endl;
      try {
        b1.signForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing AForm: " << e.what()
                  << std::endl;
      }
      std::cout << f1 << std::endl;
      try {
        b1.executeForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while executing AForm: " << e.what()
                  << std::endl;
      }
    }
  }
  {
    std::cout << std::endl << "------ Intern tests ------" << std::endl;
    Intern i;
    Bureaucrat b("Bob", 1);
    try {
      std::cout << "* try Intern makeForm with unknown form" << std::endl;
      AForm* form = i.makeForm("unknown form", "target");
      b.signForm(*form);
      b.executeForm(*form);
    } catch (Intern::NoSuchFormException& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "* try Intern makeForm with known form: shrubbery"
                << std::endl;
      AForm* form = i.makeForm("shrubbery creation", "target");
      b.signForm(*form);
      b.executeForm(*form);
    } catch (Intern::NoSuchFormException& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "* try Intern makeForm with known form: presidential"
                << std::endl;
      AForm* form = i.makeForm("presidential pardon", "target");
      b.signForm(*form);
      b.executeForm(*form);
    } catch (Intern::NoSuchFormException& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "* try Intern makeForm with known form: robotomy"
                << std::endl;
      AForm* form = i.makeForm("robotomy request", "target");
      b.signForm(*form);
      b.executeForm(*form);
    } catch (Intern::NoSuchFormException& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
