#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        
        Bureaucrat bob("Bob", 42);
        Form contract("Employment Contract", 50, 20);

        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        
        bob.signForm(contract);
        std::cout << "After signing attempt: " << contract << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        
        Bureaucrat intern("Intern", 100);
        Form nda("NDA Agreement", 75, 30);

        std::cout << intern << std::endl;
        std::cout << nda << std::endl;

        intern.signForm(nda); 
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        
        Form invalidForm("Invalid Form", 0, 20);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

