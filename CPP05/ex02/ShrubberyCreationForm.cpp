#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

// Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute function
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }
    
    outfile << "        ^        " << std::endl;
    outfile << "       ^^^       " << std::endl;
    outfile << "      ^^^^^      " << std::endl;
    outfile << "     ^^^^^^^     " << std::endl;
    outfile << "    ^^^^^^^^^    " << std::endl;
    outfile << "   ^^^^^^^^^^^   " << std::endl;
    outfile << "  ^^^^^^^^^^^^^  " << std::endl;
    outfile << "        ||       " << std::endl;
    outfile.close();

    std::cout << executor.getName() << " executed " << getName() << " and created a shrubbery at " << _target << "!" << std::endl;
}
