#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
                    // bu dosyada bir form sınıfı oluşturmaktayız sınıfımızda 
class Bureaucrat; // bu satırda Forward declaration kullanıyoruz yani Bureaucrat sınfıının içeriğine ihtiyaç duymamamıza rağmen ilerleyen süreçte varlığından emin olmamaız gerekeceği için şimdiden ilgili dosyada varlığını tanıtıyoruz

class Form { // form adında bir sınıf oluşturuyoruz
private: // private değiişkenlerinde 
    const std::string _name; // isim
    bool _isSigned;         // imzalı olup olmadığını kontrol eden bir boolen değer
    const int _signGrade;  //  imzalamak için gerekli olan sabit derece derecesi yetmeyen bürokratlar imzalama işlemi yapamayacak
    const int _executeGrade; // çalıştırmak için gerekli olan sabit derece

public: 
    // Exception classes 
    class GradeTooHighException : public std::exception { // grade değerini kontrol eden mekanizmalar
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructor and Destructor
    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // Form actions formun imzalama işlemi
    void beSigned(const Bureaucrat& bureaucrat);
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
