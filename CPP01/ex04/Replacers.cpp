#include "Replacers.hpp"

std::string    Replacer::prepair_copy(std::string line, std::string &s1, std::string &s2, int & flag)
{
    std::string ret = "";
    size_t found;
    size_t index = 0;
    size_t max = line.length();

    while (index < max)
    {
        found = line.find(s1);
        if (found != std::string::npos)
        {
            ret += line.substr(index, (found)) + s2;
            line = line.substr(((found) + s1.length()), line.length());
            flag = 1;
        }
        else
        {
            ret += line;
            index = max;
        }
    }
    return (ret);
}

void    Replacer::file_copy(std::string filename, std::string s1, std::string s2)
{
    std::string all_of;
    std::string line;
    std::string new_file_name;
    int flag = 0;
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "file could not be opened" << std::endl;
		return;
    }
    if (infile.peek() == EOF)
    {
        std::cerr << "file exists, but empty" << std::endl;
		return;
    }
    while (std::getline(infile, line))
    {
        line = this->prepair_copy(line, s1, s2, flag);
        all_of += line;
        if (infile.peek() != EOF)
            all_of += "\n";
    }
    if (!flag)
    {
        std::cerr << "file exists but does not contain the string" << std::endl;
		return;
    }
    infile.close();
    new_file_name = filename + ".replace";
    std::ofstream outFile(new_file_name);
    if (!outFile) 
    { 
        std::cerr << "File could not be created: " << new_file_name << std::endl;
        return;
    }
    outFile << all_of;
    outFile.close();
}