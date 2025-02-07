#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    //değişkenler
    const std::string _name; //-> isim
    int _grade; //-> seviye 1 ile 150 arasında olacak

public:
    // Exception classes
    class GradeTooHighException : public std::exception { // derece 1 den küçükse döndürelecek
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception { // derece 150 den büyükse " " "
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
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
