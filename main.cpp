#include "mainprocess.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    try
    {
        namespace fs = std::experimental::filesystem;

        std::string dir = {};    

        if (argc == 2)
            dir = argv[1];
        else
        {
            std::cout << "Pass me folder/directory with images: ";
            std::getline(std::cin, dir);
            dir.erase(std::remove(dir.begin(), dir.end(), '\\'), dir.end());
        }

        MainProcess map;

        std::vector<std::string> urls = map.getPath(dir);
        map.sendGpsToTxt(urls);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    EXIT_SUCCESS;
}