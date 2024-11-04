#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
    std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]" << std::endl;
    std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
    std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void    Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
    std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." <<std::endl;
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*options[4])(void);
	options[0] = &Harl::debug;
	options[1] = &Harl::info;
	options[2] = &Harl::warning;
	options[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*options[i])();
	}
}
