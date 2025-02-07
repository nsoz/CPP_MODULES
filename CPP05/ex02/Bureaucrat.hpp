#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

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
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification functions
    void incrementGrade();
    void decrementGrade();

    // Form functions
    void signForm(AForm& form);
    void executeForm(const AForm& form) const;
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
