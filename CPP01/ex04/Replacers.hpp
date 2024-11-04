#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <fstream>

class Replacer
{
    public:
        void    file_copy(std::string filename, std::string s1, std::string s2);
        std::string    prepair_copy(std::string line, std::string &s1, std::string &s2, int &flag);
};

#endif
