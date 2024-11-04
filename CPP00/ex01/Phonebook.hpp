#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact person[8];
        int current_index;
    public:
        PhoneBook();
        void    add_contact(const Contact &new_contact);
        void    print_contact() const;
        void    search_contact() const;
        const Contact& get_person(int index) const;
};

#endif