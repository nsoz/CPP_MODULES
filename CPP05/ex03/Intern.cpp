#include "Intern.hpp"


Intern::Intern() {}


Intern::Intern(const Intern& other) {
    *this = other;
}


Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}


Intern::~Intern() {}


static AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) { 
    struct FormPair {
        std::string name; 
        AForm* (*create)(const std::string& target); 
        
    }; 
    
    static const FormPair formTypes[] = { 
        {"shrubbery creation", createShrubberyForm}, 
        {"robotomy request", createRobotomyForm}, 
        {"presidential pardon", createPresidentialForm} 
    };
    
    for (size_t i = 0; i < 3; i++) {
        if (formTypes[i].name == formName) { 
        
            std::cout << "Intern creates " << formName << std::endl; 
            return formTypes[i].create(target); 
        }
    }
    
    std::cerr << "Error: Form name \"" << formName << "\" not recognized!" << std::endl;
    return nullptr;
}
