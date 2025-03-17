#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
        Intern someRandomIntern;
        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
        AForm* invalidForm = someRandomIntern.makeForm("unknown form", "Nobody");

        Bureaucrat bob("Bob", 3);
    try {
        if (form1) {
            bob.signForm(*form1);
            bob.executeForm(*form1);
        }
        if (form2) {
            bob.signForm(*form2);
            bob.executeForm(*form2);
        }
        if (form3) {
            bob.signForm(*form3);
            bob.executeForm(*form3);
        }
        Bureaucrat ibo("ibo", 0);
        
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    delete form1;
    delete form2;
    delete form3;
    delete invalidForm;
    system("leaks intern");
    return 0;
}
