#include "Contact.hpp"

std::string Contact::getname() const
{
    return (name);
}
std::string Contact::getsurname() const
{
    return (surname);
}
std::string Contact::getnickname() const
{
    return (nickname);
}
std::string Contact::getphonenumber() const
{
    return (phonenumber);
}
std::string Contact::getdarkest_secret() const
{
    return (darkest_secret);
}

void Contact::setname(std::string name_)
{
    name = name_;
}
void Contact::setsurname(std::string surname_)
{
    surname = surname_;
}
void Contact::setnickname(std::string nickname_)
{
    nickname = nickname_;
}
void Contact::setphonenumber(std::string phonenumber_)
{
    phonenumber = phonenumber_;
}
void Contact::setdarkest_secret(std::string darkest_secret_)
{
    darkest_secret = darkest_secret_;
}