#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
                    
#include <iostream>
#include <stdexcept>

class Bureaucrat {      
private: 
    const std::string _name; 
    int _grade; 

public: 
    
    class GradeTooHighException : public std::exception { 
    public: 
        const char* what() const throw(); 
    };

    class GradeTooLowException : public std::exception { 
    public:
        const char* what() const throw(); 
    };

    
    Bureaucrat(); 
    Bureaucrat(const std::string& name, int grade);  
    Bureaucrat(const Bureaucrat& other); 
    Bureaucrat& operator=(const Bureaucrat& other); 
    ~Bureaucrat(); 

    
    std::string getName() const;
    int getGrade() const;

    
    void incrementGrade();
    void decrementGrade();
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat); 

#endif
