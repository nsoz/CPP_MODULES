#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "iostream"
#include <iomanip> 

class Contact{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string phonenumber;
        std::string darkest_secret;

    public:
        std::string getname() const;
        std::string getsurname() const;
        std::string getnickname() const;
        std::string getphonenumber() const;
        std::string getdarkest_secret() const;

        void setname(std::string name_);
        void setsurname(std::string surname_);
        void setnickname(std::string nickname_);
        void setphonenumber(std::string phonenumber_);
        void setdarkest_secret(std::string darkest_secret_);
};

#endif