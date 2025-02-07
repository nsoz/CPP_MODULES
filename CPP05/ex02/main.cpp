#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 5);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Charlie");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Bob forms signing
        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        // Bob executes the forms
        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
