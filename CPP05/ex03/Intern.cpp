#include "Intern.hpp"

// Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(const Intern& other) {
    *this = other;
}

// Assignment Operator
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Helper functions to create forms
static AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// MakeForm function
AForm* Intern::makeForm(const std::string& formName, const std::string& target) { // form yaratma süreci 
    struct FormPair {// yaratılan formları tutabilmek için formPair adında bir struct yapıyoruz
        std::string name; // formun adı
        AForm* (*create)(const std::string& target); // içerisinde tüm formların temlinde yatan yapı Aform sınıfı var
        // çalışma prensibi create fonksiyon işaretçisi kendisinden sonra gelen target ismi ile birleşip bir nevi createShrubberyForm gibi bir fonksiyon çağrısı yapmaya hazırlanmakta
    }; 
    
    static const FormPair formTypes[] = { // FormPair structında create değişkeninin target değişkeni ile yaptığı hazırlık bu kısımda anlam bulmakta
        {"shrubbery creation", createShrubberyForm}, // create ve target birleşerek oluşturduğu "shrubbery creation" yapsını ilgili fonksiyona iletir
        {"robotomy request", createRobotomyForm}, // create ve target birleşerek oluşturduğu "robotomy request" yapsını ilgili fonksiyona iletir
        {"presidential pardon", createPresidentialForm} // create ve target birleşerek oluşturduğu "presidential pardon" yapsını ilgili fonksiyona iletir
    };
    
    for (size_t i = 0; i < 3; i++) {
        if (formTypes[i].name == formName) { // dışarıdan gelen FormName ile fonksiyonun başından bu yana ilgili fonksiyon yönlendirmelerini ayarladığımız
        // formTypes dizisini kıyaslayarak işleyişi başlatıyoruz
            std::cout << "Intern creates " << formName << std::endl; // yaratıldı mesajı
            return formTypes[i].create(target); // ve formu yaratarak döndürme
        }
    }
    // formName oluşturulan dizideki hiçbir name paremetresi ile eşleşmediyse hata mesajı yazdırılır
    std::cerr << "Error: Form name \"" << formName << "\" not recognized!" << std::endl;
    return nullptr;
}
