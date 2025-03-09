#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

// Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute function
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const { // çalıştırma fonksiyonu
    if (!isSigned()) // imzalı olup olmadığını kontrol eder
        throw FormNotSignedException(); // imzasız olma drumu
    if (executor.getGrade() > getExecuteGrade()) // yetki kontrolü
        throw GradeTooLowException(); // yetersiz yetki olam durumu
    
    std::ofstream outfile((_target + "_shrubbery").c_str()); // target_shrubbery adlı bir dosya oluşturur
    if (!outfile) {                                         // oluşmama durumu
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }
    
    outfile << "        ^        " << std::endl;
    outfile << "       ^^^       " << std::endl;
    outfile << "      ^^^^^      " << std::endl;
    outfile << "     ^^^^^^^     " << std::endl;
    outfile << "    ^^^^^^^^^    " << std::endl;
    outfile << "   ^^^^^^^^^^^   " << std::endl;
    outfile << "  ^^^^^^^^^^^^^  " << std::endl;
    outfile << "        ||       " << std::endl;
    outfile.close();
// oluşturulan dosyaya yukarıdaki çam ağacı şekli çizilir
    std::cout << executor.getName() << " executed " << getName() << " and created a shrubbery at " << _target << "!" << std::endl; // ve başarı mesajı standart çıktıya verilir
}
