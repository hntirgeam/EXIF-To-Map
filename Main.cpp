#include "MainProcess.hpp"

int main(int argc, char *argv[])
{
    std::string dir = {};

    if (argc < 2) 
    {
        std::cout << "Pass me folder/directory with images pls: ";
        std::cin >> dir;
    }
    else if (argc == 2)
    {
        dir = argv[1];
    }
    else
    	{
    		std::cout << "Usage: " << argv[0] << " or " << argv[0] << " [path to dirrecory with images]" << std::endl;
    		return 1;
    	}

    MainProcess map;

	try
	{
		std::vector urls = map.getPath(dir);
		map.sendGpsToTxt(urls);
	}
	catch (std::experimental::filesystem::v1::__cxx11::filesystem_error&)
	{
		std::cout << "No such file or directory." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Get error: " << e.what() << std::endl;
	}

    return 0;
}