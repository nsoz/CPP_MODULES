#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
                    //bir bureaucrat sınuıfı oluşturmak için hpp dosyasını hazırlıyoruz
#include <iostream>
#include <stdexcept>

class Bureaucrat {      // Bureaucrat isimli bir sınıf oluturuyoruz 
private: // private tipinde 
    const std::string _name; //-> isim adlı
    int _grade; //-> seviye adlı 1 ile 150 arasında olacak şekilde ayarlanmış iki değişken oluşturuyoruz

public: //public değişkenlerde
    // Exception sistem sınıfı kullanarak istisna durumlarını ele alabilmek için kendi GradeTooHighException istisna sınıfımızı oluşturuyoruz
    class GradeTooHighException : public std::exception { // derece 1 den küçük olduğunda döndüreleccek sistemi içeren sınıf 
    public: // oluşturduğumuz GradeTooHighException sınıfı derece 1 den küçük olduğunda dışarıya döndüreceği işleyişi içerir
        const char* what() const throw(); // bu satırda istisna ile alakalı hata mesajı geriye döndürülmektedir
    };

    class GradeTooLowException : public std::exception { // derece 150 den büyükse döndürelecek sistemi içeren sınıf aynı şekilde sistem sınıflarından exception sınıfını miras alarak oluşturmaktayız
    public://GradeTooLowException sınıfının public olarak ilgili durumda 
        const char* what() const throw(); // bu satırda istisna için özel hata mesajını döndürür
    };

    // Orthodox Canonical Form
    Bureaucrat(); // yapıcı constructor
    Bureaucrat(const std::string& name, int grade);  // parametreli constructor
    Bureaucrat(const Bureaucrat& other); // kopylama constructor
    Bureaucrat& operator=(const Bureaucrat& other); // assigment oprator 
    ~Bureaucrat(); //destructor

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification functions bu iki fonksiyon grade derecesini azlatıp artıran fonksiyonlardır cpp dosyasında detayına gireceğiz
    void incrementGrade();
    void decrementGrade();
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat); // out fonksiyonu kullanılarak sınıfın kendisini doğrudan yazdırılmasını sağlayan yapı

#endif
