#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp" // Form sınıfını ekledik

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

    // Orthodox Canonical Form
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

    // New function to sign forms
    void signForm(Form& form);
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
