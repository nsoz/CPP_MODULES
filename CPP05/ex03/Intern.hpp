#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern { // bir intern sınıfı tanımlıyoruz
public:  // public değişkenlerinde ortodoks kaonik
    // Constructor and Destructor
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // Form creation function
    AForm* makeForm(const std::string& formName, const std::string& target); // form yaratma fonksiyonu
};

#endif
