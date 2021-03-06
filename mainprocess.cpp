#include "mainprocess.hpp"
#include "exif.hpp"

std::vector<std::string> MainProcess::getPath(const std::string &dirPath)
{
    namespace fs = std::experimental::filesystem;

    std::vector<std::string> file_urls = { }; 

    for (auto& p: fs::recursive_directory_iterator(dirPath))
    {
        if (p.path().extension() == ".jpg" || p.path().extension() == ".jpeg" 
            || p.path().extension() == ".JPG" || p.path().extension() == ".JPEG")
        {
            file_urls.emplace_back(p.path());
        }
    }
    return file_urls;
}

void MainProcess::sendGpsToTxt(const std::vector<std::string> &file_urls)
{
    double lat = 0, lon = 0, alt = 0;

    std::ofstream txt;

    if (!file_urls.empty())
    {
        txt.open ("gps_coordinates.txt");

        for(auto &file : file_urls)
        {
            retrieveGpsCoordinate(file, lat, lon, alt);
            if (lat != 0.0 && lon != 0.0)
            {
                std::cout << "Added successfully:\t\"" << file << "\"" << '\n';
                txt << lat << " " << lon << " " << alt << "\n";
            }
        }
        std::cout << "\nDone! Now you can run map.py" << '\n';
    }
    else
    {
        std::cerr << "Sorry, but no matching files were found" << '\n';
    }

    txt.close();
}

void MainProcess::retrieveGpsCoordinate(std::string file_name, double &lat, double &lon, double &alt)
{
    FILE *fp = fopen(file_name.c_str(), "rb");
    if (!fp)
    {
        std::cerr << "Sorry. I can't parse this file yet:\t\"" << file_name << "\"" <<'\n';
    }
    fseek(fp, 0, SEEK_END);
    unsigned long fsize = ftell(fp);
    rewind(fp);
    auto *buf = new unsigned char[fsize];
    if (fread(buf, 1, fsize, fp) != fsize)
    {
        delete[] buf;
        std::cerr << "Sorry. I can't parse this file yet:\t\"" << file_name << "\"" <<'\n';
    }
    fclose(fp);

    easyexif::EXIFInfo result;
    int code = result.parseFrom(buf, fsize);
    delete[] buf;
    if (code)
    {
        std::cerr << "Sorry. I can't parse this file yet:\t\"" << file_name << "\"" <<'\n';
    }

    lat = result.GeoLocation.Latitude;
    lon = result.GeoLocation.Longitude;
    alt = result.GeoLocation.Altitude;
}