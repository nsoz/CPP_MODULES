#include "Phonebook.hpp"

static int digit_check(std::string value)
{
    for (std::string::size_type i = 0; i < value.length(); i++)
    {
        if (!(value[i] >= '0' && value[i] <= '9'))
            return 0;
    }
    return 1;
}

static int is_the_data_confirmed(int flag, std::string value)
{
    if (flag == 1 || flag == 2 || flag == 3 || flag == 5)
    {
        if (value == "")
        {
            std::cout << "data cant be empty" << std::endl;
            return (0);
        }
        else
            return (1);
    }
    else
    {
        if (value == "")
        {
            std::cout << "data cant be empty" << std::endl;
            return (0);
        }
        if (!digit_check(value))
        {
            std::cout << "phone number must consist of numbers" << std::endl;
            return (0);
        }
        else
            return (1);
    }
}

static void prepair_add(PhoneBook &my_phonebook)
{
    Contact new_contact;
    std::string value;
    int x = 1; 
    while (x <= 5)
    {
        if (x == 1)
        {
            std::cout << "Name of your new contact" << std::endl;
            std::getline(std::cin, value);
            if (is_the_data_confirmed(x, value))
            {
                new_contact.setname(value);
                x++;
            }
        }
        else if (x == 2)
        {
            std::cout << "Surname of your new contact" << std::endl;
            std::getline(std::cin, value);
            if (is_the_data_confirmed(x, value))
            {
                new_contact.setsurname(value);
                x++; 
            }
        }
        else if (x == 3)
        {
            std::cout << "Nickname of your new contact" << std::endl;
            std::getline(std::cin, value);
            if (is_the_data_confirmed(x, value))
            {
                new_contact.setnickname(value);
                x++; 
            }
        }
        else if (x == 4)
        {
            std::cout << "Phone number of your new contact" << std::endl;
            std::getline(std::cin, value);
            if (is_the_data_confirmed(x, value))
            {
                new_contact.setphonenumber(value);
                x++;
            }
        }
        else if (x == 5)
        {
            std::cout << "Darkest secret of your new contact" << std::endl;
            std::getline(std::cin, value);
            if (is_the_data_confirmed(x, value))
            {
                new_contact.setdarkest_secret(value);
                x++;
            }
        }
    }
    my_phonebook.add_contact(new_contact);
    std::cout << new_contact.getname() << " has been added to PhoneBook" << std::endl;
}

int main()
{
    PhoneBook my_phonebook;
    std::string chosen;
    std::cout << "welcome to phone book" << std::endl;
    while (1)
    {
        std::cout << "ADD => Add some new person to phone book" << std::endl;
        std::cout << "SEARCH => Search and list phone book members" << std::endl;
        std::cout << "EXIT => Exit from the phone book" << std::endl;
        std::getline(std::cin, chosen);
        if (chosen == "ADD" || chosen == "add")
            prepair_add(my_phonebook);
        else if (chosen == "SEARCH" || chosen == "search")
            my_phonebook.search_contact();
        else if (chosen == "EXIT" || chosen == "exit")
            return (0);
        else
            std::cout << "nonexistent option" << std::endl;
    }
}