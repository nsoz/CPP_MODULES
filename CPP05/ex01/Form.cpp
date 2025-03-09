#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {} // yapıcı liste ile başlatılıyor

Form::Form(const std::string& name, int signGrade, int executeGrade) // parametreli constructor 
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) { // adlığı parametreleri yapıcı liste ile yerleştiriyor
    if (signGrade < 1 || executeGrade < 1) // grade işlemlerini kontrol bloklarından geçiriyor istisnai bir durum varsa işlevini gerçekleştiriyor
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

// Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

// Be Signed Function imzalama işleminin gerçekleştiği yer
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) // eğer ki bürokratın derecesi formun derecesinden  sayısal olarak büyük işleyiş olarak düşük ise imza işlemini devam ettirmez
        throw GradeTooLowException(); // istisna mesajını döndürecek
    _isSigned = true; // yetki yeterli ise imzalama işlemi gerçekleşecek
}

// Exception Messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Required Sign Grade: " << form.getSignGrade()
       << ", Required Execute Grade: " << form.getExecuteGrade();
    return os;
}
