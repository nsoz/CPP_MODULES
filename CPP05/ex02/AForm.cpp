#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {} 

AForm::AForm(const std::string& name, int signGrade, int executeGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}


AForm& AForm::operator=(const AForm& other) {
    if (this != &other) { 
        _isSigned = other._isSigned; 
    }
    return *this; 
}


AForm::~AForm() {}


std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}


void AForm::beSigned(const Bureaucrat& bureaucrat) { 
    if (bureaucrat.getGrade() > _signGrade) 
        throw GradeTooLowException(); 
    _isSigned = true;
}


const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed! Cannot execute.";
}


std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << form.getSignGrade()
       << ", Required Execute Grade: " << form.getExecuteGrade();
    return os;
}