// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"


// int main(void)
// {
// 	ScavTrap s("ALONS-Y");
// 	ScavTrap s1 = s;
//     ScavTrap a;
// 	s.attack("zatıru");
// 	s.attack("ZutTuRu");
// 	s.takeDamage(500);
// 	s.takeDamage(500);
// 	s.beRepaired(500);
// 	s.takeDamage(500);
// 	s.takeDamage(1);
//     s.guardGate();
// }

#include "ScavTrap.hpp"

int main() {
    // Varsayılan yapıcıyı test et
    std::cout << "=== Default Constructor Test ===" << std::endl;
    ScavTrap defaultScav;

    // Parametreli yapıcıyı test et
    std::cout << "\n=== Parameterized Constructor Test ===" << std::endl;
    ScavTrap namedScav("Guardian");

    // Kopya yapıcıyı test et
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    ScavTrap copiedScav(namedScav);

    // Atama operatörünü test et
    std::cout << "\n=== Copy Assignment Operator Test ===" << std::endl;
    ScavTrap assignedScav;
    assignedScav = namedScav;

    // attack() metodunu test et
    std::cout << "\n=== Attack Method Test ===" << std::endl;
    namedScav.attack("Enemy1");
    namedScav.attack("Enemy2");

    // Enerji tükenmesi durumunu test et
    std::cout << "\n=== Attack Method - Out of Energy Test ===" << std::endl;
    for (int i = 0; i < 50; ++i) { // Tüm enerjiyi tüket
        namedScav.attack("DummyTarget");
    }

    // guardGate() metodunu test et
    std::cout << "\n=== Guard Gate Method Test ===" << std::endl;
    namedScav.guardGate();

    // Yıkıcıyı test etmek için nesneleri yok et
    std::cout << "\n=== Destructor Test ===" << std::endl;
    // main'den çıkarken otomatik olarak yıkıcılar çağrılacak

    return 0;
}
