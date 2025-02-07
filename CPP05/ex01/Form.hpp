#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat; // Forward declaration

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructor and Destructor
    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // Form actions
    void beSigned(const Bureaucrat& bureaucrat);
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
