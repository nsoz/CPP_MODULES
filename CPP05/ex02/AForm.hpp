#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat; // Forward declaration bunu yapmamızın sebebi ileride Bureaucrat sınıfının içeriğine ihtiyaç duymasakta ileride bu sınıfın varlığını ihtiyaç duyacağız

class AForm { //bir Aform clası oluşturuyoruz
private: //Private değişkenleri 
    const std::string _name; // isim
    bool _isSigned; //imzalı olup olmadığını tutan bir boolen değer
    const int _signGrade; // imzalanma derecesi (gerekeli olan imzalayabilme yetkisi)
    const int _executeGrade; // çalıştırabilmek için gerekli olan sabit derece

public: //public değişkenlerde 
    // Exception classes
    class GradeTooHighException : public std::exception { // istisnai durumları kontrol edebilmek için exception sınıfı aracılığı ile oluşturduğumuz iki adet farklı sınıfımız var 
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception { // bu kısımda da henüz imzalanmamış bir formun çalıştırılamya çalışıldığı durumda dönen bir istisna durumu 
    public:                                               // Aform sınıfını form sınıfından ayıran özelliklerden biri de budur
        const char* what() const throw();
    };

    // Constructor and Destructor
    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    // Form actions
    void beSigned(const Bureaucrat& bureaucrat); // bu fonksiyon ise inzalana işleminin yapıldığı fonksiyondur
    virtual void execute(const Bureaucrat& executor) const = 0; // Pure virtual fonksiyon oalrak tanımladık = 0 diyerek. 
    //buradaki amacımız Aform sınfının Form sınıfının aksine sanal bir sınıf olduğunu belirttik ve Aform sınıfından miras alarak oluşturulacak sınıf kendi execute fonksiyonuınun nasıl çalışması gerektiğini kendi belirleyecektir
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const AForm& form); // cout fonksiyonun da yazdırlabilir bi hale getirmek amacıyla bulundurduğumuz << operatörü

#endif
