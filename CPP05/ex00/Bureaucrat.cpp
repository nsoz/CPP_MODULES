#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {} //yapıcı listei le dorğudan atamaları yapıyoruz

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) { // yapıcı liste aracılığı ile name paremetresini doğrudan sınıf içeriğine kaydediyoruz grade içinde bir kontrol mekanizması kullanıyoruz
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade; // kontrollerden geçerse eşitlemey iyapıyoruz
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {} // yapcı liste ile kopyalam constructorunu işlevsel hale getiriyoruz 

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) { // eşitleme operatörü
    if (this != &other) { // eşit olan iki yapıyı bir birine eşitleme işlemi yapmamak için
        _grade = other._grade; // eşitleme işlemi
    }
    return *this; // *this şeklinde return ediyoruz bu da zincirleme eşitlemelere uygun hale getiriyor a = b = c gibi
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters
std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Grade Modification Functions
void Bureaucrat::incrementGrade() { // grade artrıma fonksiyonu 
    if (_grade == 1)  // grade artabileceği max değerde iken artırılmaya çalışılınca istisna fonksiyınunu "GradeTooHighException" fırlatıp artırma işelmini engeller
        throw GradeTooHighException(); // istisna fonksiyomnu fırlatırılır
    _grade--; //ifden kurtulursa artırma işelmi yapılır 1 en yüksek olduğu için -- işelmi yapıyoruz
}

void Bureaucrat::decrementGrade() { // grade azaltma fonksiyınu
    if (_grade == 150) // grade azalabileceği min değerde ise istisna mesajı döndürülür ve azaltma işlemi gerçekleştirilmez
        throw GradeTooLowException(); // istisna fonksiyoınu fıtlatılır
    _grade++; //if bloğuna takılmadığı taktirde grade azaltılır 150 en düşük bu yüzden ++ işlemi yapmaktayız
}

// Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const throw() { // GradeTooHighException sınıfınnın fırlatıldığında "Grade too high!" mesajını döndürmesini sağlamakta 
    return "Grade too high!"; //what parametresi ilgili mesajı çeken yapıdır
}

const char* Bureaucrat::GradeTooLowException::what() const throw() { // GradeTooLowException  sınıfınnın fırlatıldığında "Grade too low!" mesajını döndürmesini sağlamakta 
    return "Grade too low!"; //what parametresi ilgili mesajı çeken yapıdır
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) { // cout fonksiyonu ile yazılmaya çalışıldığında sınıfın yazdırılabilir olmasını sağlayan operatör
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
// ostream sınıfı cout kullanılırken yazılmak istenilen mesajı önce içine alan sınıftır burada ise couta hazır hale getirmek için os parametresine ilgili mesajları aktarmaktayız
