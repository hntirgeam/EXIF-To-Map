#include "mainprocess.h"

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    

    std::string dir = {};

    if (argc < 2) 
    {
        std::cout << "Pass me folder/directory with images pls: ";
        std::cin >> dir;
    }
    else
    {
        dir = argv[1];
    }

    MainProcess map;

    std::vector urls = map.getPath(dir);
    map.sendGpsToTxt(urls);

    return 0;
}