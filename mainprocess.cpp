#include "mainprocess.h"
#include "exif.h"

void MainProcess::sendGpsToTxt(const std::string file_name, double *lat, double *lon, double *alt)
{
    std::ofstream file;
    file.open ("gps_coordinates.txt");
    file << &lat << " " << &lon << " " << &alt << "\n";
    file.close();
}

std::string MainProcess::getPath(const std::string dirPath)
{
    namespace fs = std::experimental::filesystem;
    
    std::vector<std::string> findExtension = {"*.jpg", "*.jpeg"}; 

    try
    {
        if(fs::exists(dirPath) && fs::is_directory(dirPath))
        {
            fs::recursive_directory_iterator iter(dirPath);
            fs::recursive_directory_iterator end;

            while (iter != end)
            {
                if (fs::is_directory(iter->path()) && 
                    (std::find(findExtension.begin(), findExtension.end(), iter->path().filename()) == findExtension.end()));
                    {
                        std::cout << iter->path() << '\n';
                    }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
}

void MainProcess::printToConsole()
{
    
}

// Code below somehow works, but I have barely any thoughts WHY and HOW.

void MainProcess::retrieveGpsCoordinate(std::string file_name, double &lat, double &lon, double &alt)
{
    FILE *fp = fopen(file_name.c_str(), "rb");
    if (!fp)
    {
        std::cout << "Sorry. I can't parse this file type yet" << '\n';
    }
    fseek(fp, 0, SEEK_END);
    unsigned long fsize = ftell(fp);
    rewind(fp);
    unsigned char *buf = new unsigned char[fsize];
    if (fread(buf, 1, fsize, fp) != fsize)
    {
        delete[] buf;
        std::cout << "Sorry. I can't parse this file type yet" << '\n';
    }
    fclose(fp);

    easyexif::EXIFInfo result;
    int code = result.parseFrom(buf, fsize);
    delete[] buf;
    if (code)
    {
        std::cout << "Sorry. I can't parse this file type yet" << '\n';
    }

    lat = result.GeoLocation.Latitude;
    lon = result.GeoLocation.Longitude;
    alt = result.GeoLocation.Altitude;
}