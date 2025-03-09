#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm { // burada Aformdan miras alan bir PresidentialPardonForm sınıfı oluşturuyoruz
private:                                     // Private değerlerde 
    std::string _target;                    // Target adında bir string bulunduruyor

public:                                   // public değişkkenlerinde ise otodok kaonik
    // Constructor and Destructor
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    // Execute function override
    void execute(const Bureaucrat& executor) const; // Aform sınıfında sanal bir şekilde olan execute fonksiyonunu bu sınıfda tanımlayacağız
};

#endif