#include "mainprocess.hpp"

#include <iostream>
#include <vector>
#include <string>

int main()
{
    namespace fs = std::experimental::filesystem;

    std::string dir = {};    
    
    while(true)
    {

        std::cout << "Pass me folder/directory with images pls: ";
        std::getline(std::cin, dir);

        if(!fs::is_directory(dir))
        {
            std::cerr << "Not a directory\n";
            continue;
        }

        if(fs::is_empty(dir))
        {
            std::cerr << "Directory is empty\n";
            continue;
        }
        break;
    }

    MainProcess map;

    std::vector<std::string> urls = map.getPath(dir);
    map.sendGpsToTxt(urls);

    return 0;
}