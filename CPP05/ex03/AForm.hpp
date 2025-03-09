#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat; 

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

public:
    
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    
    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    
    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0; 
};


std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
