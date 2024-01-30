#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target)
    : AForm("Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
    : AForm(other), target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm& other) {
  target = other.target;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException(
        "AForm::GradeTooLowException: gradeToExecute");
  if (getSignature() == false)
    throw AForm::FormNotSignedException(
        "AForm::FormNotSignedException: getSignature");
  
  std::string filename = target + "_shrubbery";
  std::ofstream outfile(filename);
  if(!outfile.good())
    throw std::runtime_error("std::runtime_error: " + filename + " is not good.");
  
  std::string shrubbery =
  '       _-_                 ###             %%%,%%%%%%%            ' +
  '    /~~   ~~\             #o###             ,"%% \\-*%%%%%%%      ' +
  ' /~~         ~~\        #####o###     ;%%%%%*%   _%%%%"           ' +
  ' /~~         ~~\        #####o###     ;%%%%%*%   _%%%%"           ' +
  '{               }      #o#\#|#/###     ,%%%       \(_.*%%%%.      ' +
  ' \  _-     -_  /        ###\|/#o#      % *%%, ,%%%%*(    "        ' +
  '   ~  \\ //  ~           # }|{  #    %^     ,*%%% )\|,%%*%,_      ' +
  '_- -   | | _- _            }|{            *%    \/ #).-"*%%*      ' +
  '  _ -  | |   -_                               _.) ,/ *%,          ' +
  '      // \\                           _________/)#(_____________  ';

  outfile << shrubbery;
}
