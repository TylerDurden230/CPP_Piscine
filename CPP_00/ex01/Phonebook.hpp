#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACT 8
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"

#include <iostream>
#include <string>
#include "contact.hpp"
#include <iomanip>
#include <algorithm>
#include <cctype>

class Phonebook {
    private:
        Contact contact[MAX_CONTACT];
        int     index;
        bool    empty;
    public:
        Phonebook();
        void    setEmpty();
        bool    getEmpty();
        void    add_contact();
        int     get_index();
        Contact get_contact(int index);
        int     check_field(std::string str);
        bool    check_contact(Contact contact);
        void    show_contacts();        
        void    show_full_contact(int i);
        ~Phonebook();
};

#endif