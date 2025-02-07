#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Geçerli bir Bureaucrat nesnesi oluşturma
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;

        // Dereceyi artırma
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // Dereceyi azaltma
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Geçersiz bir Bureaucrat nesnesi oluşturma (çok yüksek derece)
        Bureaucrat boss("Boss", 0);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // Geçersiz bir Bureaucrat nesnesi oluşturma (çok düşük derece)
        Bureaucrat intern("Intern", 151);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // En yüksek dereceye ulaşma ve artırma denemesi
        Bureaucrat elite("Elite", 1);
        std::cout << elite << std::endl;
        elite.incrementGrade(); // Burada hata verecek
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        // En düşük dereceye ulaşma ve azaltma denemesi
        Bureaucrat rookie("Rookie", 150);
        std::cout << rookie << std::endl;
        rookie.decrementGrade(); // Burada hata verecek
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
