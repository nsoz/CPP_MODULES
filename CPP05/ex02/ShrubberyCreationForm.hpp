#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm { // burada Aformdan miras alan bir ShrubberyCreationForm sınıfı oluşturuyoruz
private:
    std::string _target; // isim verisi

public: // ortodoks kaonik form
    // Constructor and Destructor 
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // Execute function override
    void execute(const Bureaucrat& executor) const; // çalıştırma fonksiyonu Aformda sanal olan
};

#endif
