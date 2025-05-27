#include "ScalarConverter.hpp"
#include <string>
#include <cstdlib>
#include <climits> 
#include <cerrno>

static int parseIntC98(const std::string &str)
{
    char *endptr;
    errno = 0;
    long value = std::strtol(str.c_str(), &endptr, 10);
    if (*endptr != '\0' || errno == ERANGE)
        throw std::exception();
    if (value < INT_MIN || value > INT_MAX)
        throw std::exception();
    return static_cast<int>(value);
}

static float parseFloatC98(const std::string &str)
{
    char *endptr;
    errno = 0;
    double value = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' || errno == ERANGE)
        throw std::exception();
    return static_cast<float>(value);
}

static double parseDoubleC98(const std::string &str)
{
    char *endptr;
    errno = 0;
    double value = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' || errno == ERANGE)
        throw std::exception();
    return value;
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &org)
{
    *this = org;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this == &other)
    {
        *this = other;
    }
    return *this;
}

bool ScalarConverter::isStringEqual(const std::string &str)
{
    const std::string arr[] = {
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff"};

    for (int i = 0; i < 6; i++)
    {
        if (str == arr[i])
            return true;
    }
    return false;
}

void ScalarConverter::checkValue(const std::string &str)
{
    if (!isStringEqual(str) && str.length() != 1)
    {
        const std::string allowedCharacters = "0123456789.f-+";
        for (size_t i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (allowedCharacters.find(c) == std::string::npos)
            {
                std::cerr << "it is not convertable" << std::endl;
                exit(2);
            }
        }
    }
    if (str.find(".") != std::string::npos)
    {
        size_t d = str.find(".");
        if (d == 0 || d != str.find_last_of(".") || d == str.length() - 1)
        {
            std::cerr << ("wrong dot usage") << std::endl;
            exit(3);
        }
    }
    if (str.find("f") != std::string::npos)
    {
        size_t f = str.find("f");
        if ((f == 0 || f != str.find_last_of("f") || str[f - 1] == '.') && str.length() != 1)
        {
            std::cerr << ("wrong f usage") << std::endl;
            exit(4);
        }
    }
    if ((str.find("+") != std::string::npos) || (str.find("-") != std::string::npos))
    {
        if (str.find("-") != str.find_last_of("-") || str.find("+") != str.find_last_of("+"))
        {
            std::cerr << ("multiple +/- not allowed") << std::endl;
            exit(5);
        }
        int a = str.find("-");
        if (a == 0 || a == 1)
        {
            if (str[a + 1] == '+' || str[a - 1] == '+')
            {
                std::cerr << ("+- or -+ not allowed") << std::endl;
                exit(6);
            }
        }
    }
}

int ScalarConverter::checkRange(std::string type, std::string str)
{
    int i = 0;
    if (type == "char" || type == "int")
    {
        try
        {
            i = parseIntC98(str);
        }
        catch (const std::exception &)
        {
            std::cout << type + ": impossible" << std::endl;
            return -1;
        }
    }
    else if (type == "float")
    {
        try
        {
            parseFloatC98(str);
        }
        catch (const std::exception &)
        {
            std::cout << type + ": impossible" << std::endl;
            return -1;
        }
    }
    else if (type == "double")
    {
        try
        {
            parseDoubleC98(str);
        }
        catch (const std::exception &)
        {
            std::cout << type + ": impossible" << std::endl;
            return -1;
        }
    }
    return i;
}

void ScalarConverter::convert(const std::string &str)
{
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}

void ScalarConverter::toChar(const std::string &str)
{
    char c;

    if (isStringEqual(str))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (str.length() == 1)
    {
        c = str.at(0);
        std::cout << "char: '" << c << "'" << std::endl;
        return;
    }
    int i = checkRange("char", str);
    if (i != -1 && (i < 32 || i > 127))
    {
        std::cout << "char: not displayable" << std::endl;
        return;
    }
    if (i != -1)
    {
        c = static_cast<char>(i);
        std::cout << "char: '" << c << "'" << std::endl;
    }
}

void ScalarConverter::toInt(const std::string &str)
{
    int i;

    if (isStringEqual(str))
    {
        std::cout << "int : impossible" << std::endl;
        return;
    }
    if (str.length() == 1)
    {
        if (isdigit(str[0]) == 0)
            i = static_cast<int>(str[0]);
        else
            i = std::atoi(str.c_str());
        std::cout << "int: " << i << std::endl;
        return;
    }
    i = checkRange("int", str);
    if (i != -1)
        std::cout << "int: " << i << std::endl;
}

void ScalarConverter::toFloat(const std::string &str)
{
    float f;

    if (isStringEqual(str))
    {
        std::cout << "float: " << str << "f" << std::endl;
        return;
    }
    if (str.length() == 1)
    {
        if (isdigit(str[0]) == 0)
            f = static_cast<float>(str[0]);
        else
            f = static_cast<float>(std::atof(str.c_str()));
        std::cout << "float: " << f << "f" << std::endl;
        return;
    }
    int i = checkRange("float", str);
    if (i != -1)
    {
        try
        {
            f = parseFloatC98(str);
        }
        catch (...)
        {
            return;
        }
        if ((f - static_cast<int>(f)) == 0.0f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }
}

void ScalarConverter::toDouble(const std::string &str)
{
    double d;
    if (isStringEqual(str))
    {
        std::cout << "double: " << str << std::endl;
        return;
    }
    if (str.length() == 1)
    {
        if (isdigit(str[0]) == 0)
            d = static_cast<double>(str[0]);
        else
            d = std::atof(str.c_str());
        std::cout << "double: " << d << std::endl;
        return;
    }
    int i = checkRange("double", str);
    if (i != -1)
    {
        try
        {
            d = parseDoubleC98(str);
        }
        catch (...)
        {
            return;
        }
        if ((d - static_cast<int>(d)) == 0.0)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
}