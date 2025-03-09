#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
                    
class Bureaucrat; 

class Form { 
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

    
    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    
    void beSigned(const Bureaucrat& bureaucrat);
};


std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
