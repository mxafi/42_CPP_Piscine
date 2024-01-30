#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm& other) {
  target_ = other.target_;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: gradeToExecute");
  if (getSignature() == false)
    throw AForm::FormNotSignedException(
        "AForm::FormNotSignedException: getSignature");
  
  std::string filename = target_ + "_shrubbery";
  std::ofstream outfile(filename);
  if(!outfile.good())
    throw std::runtime_error("std::runtime_error: " + filename + " is not good.");
  
  std::string shrubbery =
  std::string("       _-_                 ###             %%%,%%%%%%%            \n") +
  "    /~~   ~~\\             #o###             ,\"%% \\\\-*%%%%%%%      \n" +
  " /~~         ~~\\        #####o###     ;%%%%%*%   _%%%%\"           \n" +
  " /~~         ~~\\        #####o###     ;%%%%%*%   _%%%%\"           \n" +
  "{               }      #o#\\#|#/###     ,%%%       \\(_.*%%%%.      \n" +
  " \\  _-     -_  /        ###\\|/#o#      % *%%, ,%%%%*(    \"        \n" +
  "   ~  \\\\ //  ~           # }|{  #    %^     ,*%%% )\\|,%%*%,_      \n" +
  "_- -   | | _- _            }|{            *%    \\/ #).-\"*%%*      \n" +
  "  _ -  | |   -_                               _.) ,/ *%,          \n" +
  "      // \\\\                           _________/)#(_____________  \n";

  outfile << shrubbery;
}
