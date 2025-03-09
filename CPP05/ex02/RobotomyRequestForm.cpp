#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {} //  yapıcı liste ile başlatıldı

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {} // yapıcı liste ile başlatıldı (Aform parametreli constructor kullanıldı)

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) // yapıcı liste ile başlatıldı (Aform kopyalama constructor kullanıldı)
    : AForm(other), _target(other._target) {}

// Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) { // bir birine eşitleme durumu kontrolü
        AForm::operator=(other);
        _target = other._target;
    }
    return *this; //zincirleme atama imkanı
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute function
void RobotomyRequestForm::execute(const Bureaucrat& executor) const { //çalıştırma fonksiyonu
    if (!isSigned()) // imzalı olup olmadığının kontrolü
        throw FormNotSignedException(); // imzasız olma durumunda çalıştırılacak fonksiyon
    if (executor.getGrade() > getExecuteGrade()) // executor (çalıştırma işlemini yapmaya çalışan Bureaucrat) derecesi ile imza yetkisi sınırının kıyaslanması 
        throw GradeTooLowException(); // yetersiz grade durumunda (ki matematiksel olarak tam zıttıdır) low fonksiyonu fırlatılır
    
    std::cout << "Bzzzz... Drilling noises... 🤖" << std::endl;
    std::srand(std::time(0)); // bu kısımda amacımız robotun çalışmasını simüle etmek srand fonksiyonu Rand fonksiyonu ile birlikte çalışarak rastgele sayı üretir 
    // srand'in buradaki görevi seed'i yani bu sayıların minimum kaç olabileceğini belirler time fonksiyonu ise bu konuda srand'e yardımcı olarak işletim
    //sissteminin saatinin saniye cinsinden alır ve bu veriyi seed olarak tanımlaması için srande verir
    if (std::rand() % 2) // rand'in 2 ye kalanından gelecek sonuca göre işleyişe devam eder yani %50
        std::cout << _target << " has been successfully robotomized!" << std::endl; // başarı mesajı
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl; // başarısızlık mesajı
}