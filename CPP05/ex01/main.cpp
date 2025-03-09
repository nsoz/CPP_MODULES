#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Geçerli bir Bureaucrat ve Form oluşturma
        Bureaucrat bob("Bob", 42);
        Form contract("Employment Contract", 50, 20);

        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        // Bob formu imzalamayı deniyor
        bob.signForm(contract);
        std::cout << "After signing attempt: " << contract << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Derecesi çok düşük bir Bureaucrat formu imzalamaya çalışıyor
        Bureaucrat intern("Intern", 100);
        Form nda("NDA Agreement", 75, 30);

        std::cout << intern << std::endl;
        std::cout << nda << std::endl;

        intern.signForm(nda); // Hata verecek
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Geçersiz Form derecesi denemesi
        Form invalidForm("Invalid Form", 0, 20);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

