#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
      std::cout << std::endl << "------ Form tests ------" << std::endl;
      std::cout << "* test signing with low grade" << std::endl;
      Form f("F1A", 50, 25);
      Bureaucrat b("Bob", 51);
      std::cout << f << std::endl << b << std::endl;
      try {
        b.signForm(f);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing form: " << e.what()
                  << std::endl;
      }
      std::cout << f << std::endl;
    }
    {
      std::cout << "* test signing with high grade" << std::endl;
      Form f("F1A", 50, 25);
      Bureaucrat b("Bob", 5);
      std::cout << f << std::endl << b << std::endl;
      try {
        b.signForm(f);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing form: " << e.what()
                  << std::endl;
      }
      std::cout << f << std::endl;
      std::cout << "* test signing already signed form with high grade"
                << std::endl;
      Bureaucrat as("LateBloomer", 5);
      std::cout << f << std::endl << as << std::endl;
      try {
        as.signForm(f);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing form: " << e.what()
                  << std::endl;
      }
    }
    {
      std::cout << "* test constructing forms with out of range grades"
                << std::endl;
      try {
        Form f1("F1A", 0, 50);
      } catch (std::exception& e) {
        std::cout << "Should be highSign: " << e.what() << std::endl;
      }
      try {
        Form f1("F1A", 151, 50);
      } catch (std::exception& e) {
        std::cout << "Should be lowSign: " << e.what() << std::endl;
      }
      try {
        Form f1("F1A", 50, 0);
      } catch (std::exception& e) {
        std::cout << "Should be highExec: " << e.what() << std::endl;
      }
      try {
        Form f1("F1A", 50, 151);
      } catch (std::exception& e) {
        std::cout << "Should be lowExec: " << e.what() << std::endl;
      }
    }
  }
}
