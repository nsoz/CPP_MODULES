#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
    current_index = 0;
}

const Contact& PhoneBook::get_person(int index) const
{
    return person[index];
}

void PhoneBook::add_contact(const Contact &new_contact)
{
    person[current_index] = new_contact;
    current_index = (current_index + 1) % 8;
}

static void print_contact_utils(const std::string& var)
{
    if (var.length() <= 10)
        std::cout << std::setw(10) << var << "|";
    else
        std::cout << var.substr(0, 9) << ".|";
} 



void PhoneBook::print_contact() const
{
    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|      Name|   Surname|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (person[i].getname() == "")
            break ;
        else
        {
            std::cout << "|";
            std::cout << std::setw(10) << i + 1 << "|";
            print_contact_utils(person[i].getname());
            print_contact_utils(person[i].getsurname());
            print_contact_utils(person[i].getnickname());
            std::cout << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;
}

void PhoneBook::search_contact() const
{
    int i = 0;
    bool valid = false;
    if (person[i].getname() == "")
        std::cout << "There is no person to list or search, please add a contact" << std::endl;
    else
    {
        print_contact();
        while (!valid)
        {
            std::cout << "Please write the number of the relevant person" << std::endl;
            std::cin >> i;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
            }
            else if (i >= 1 && i <= 8 && person[i - 1].getname() != "")
                valid = true;
            else
                std::cout << "Incorrect selection or empty index" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Name: " << person[i - 1].getname() << std::endl;
        std::cout << "Surname: " << person[i - 1].getsurname() << std::endl;
        std::cout << "Nickname: " << person[i - 1].getnickname() << std::endl;
        std::cout << "Phone Number: " << person[i - 1].getphonenumber() << std::endl;
        std::cout << "Darkest Secret: " << person[i - 1].getdarkest_secret() << std::endl;
        std::cout << "-->Enter to continue<--" << std::endl;
        std::cin.ignore();
        std::cin.get();
    }
}
