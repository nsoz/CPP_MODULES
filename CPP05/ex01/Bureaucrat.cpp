#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {} // yapıcı liste ile başlatıldı

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

// Copy Constructor yapıcı liste ile başlatıldı
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) { // aynı iki paremtereyi bir birine eşitlememek için alınan önlem
        _grade = other._grade;
    }
    return *this; //*this -> zincirleme atama olanağı
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
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

// Signing Form Function imzalama aşaması
void Bureaucrat::signForm(Form& form) {
    try { //imzalama deneniyor 
        form.beSigned(*this); //ilgili bürokrat formu imzalamaya çalışıyor eğer bir exception dönerse catch bloğundaki referans exceptionu yakalayarak işeleve devam ediyor
        std::cout << _name << " signed " << form.getName() << std::endl; // imzalama başarılı ise başaralı mesajını veriyor
    } catch (std::exception& e) { // referans bir istisna sınıfını yakaladıysa
        std::cout << _name << " couldn't sign " << form.getName()  // imza işlemi tamamlanamamıştır demek bu yüzden olumsuz mesaj yazdırılır
                  << " because " << e.what() << std::endl; //e.what ise grade'in yetersiz olma sebebini yansıtır
    }
}

// Exception Messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
