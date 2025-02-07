#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

// Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute function
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


