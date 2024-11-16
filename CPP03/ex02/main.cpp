#include "FragTrap.hpp"

int main() {
    // Varsayılan yapıcıyı test et
    std::cout << "=== Default Constructor Test ===" << std::endl;
    FragTrap defaultFrag;

    // Parametreli yapıcıyı test et
    std::cout << "\n=== Parameterized Constructor Test ===" << std::endl;
    FragTrap namedFrag("Hero");

    // Kopya yapıcıyı test et
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    FragTrap copiedFrag(namedFrag);

    // Atama operatörünü test et
    std::cout << "\n=== Copy Assignment Operator Test ===" << std::endl;
    FragTrap assignedFrag;
    assignedFrag = namedFrag;

    // highFivesGuys() metodunu test et
    std::cout << "\n=== High Fives Method Test ===" << std::endl;
    namedFrag.highFivesGuys();

    // Yıkıcı testi
    std::cout << "\n=== Destructor Test ===" << std::endl;
    // Yıkıcılar otomatik olarak çalışacak

    return 0;
}
