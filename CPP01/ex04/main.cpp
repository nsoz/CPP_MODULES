#include "Replacers.hpp"

int main(int ac, char**av)
{
    if (ac != 4)
    {
        std::cout << "wrong number of entries" << std::endl;
        return 1;
    }
    std::string av_a = av[1];
    std::string av_b = av[2];
    std::string av_c = av[3];
    if (av_a.length() == 0 || av_b.length() == 0 || av_c.length() == 0)
        std::cout << "wrong number of entries" << std::endl;

    Replacer replace;
    replace.file_copy(av_a, av_b, av_c);

    return (0);
}
