#include "MainProcess.hpp"

static bool isPhotoExtention(const std::string& aExtention)
{
	static const auto photoExtentions = {".jpg", ".jpeg", ".JPG", ".JPEG"};

	return std::any_of(
			photoExtentions.begin(),
			photoExtentions.end(),
			[&](auto &aPhotoExtention)
			{
				return aExtention == aPhotoExtention;
			});
}

std::vector<std::string> MainProcess::getPath(const std::string& dirPath)
{
    namespace fs = std::experimental::filesystem;
    
    std::vector<std::string> file_urls;

    for (auto& p: fs::recursive_directory_iterator(dirPath))
    {
        if (isPhotoExtention(p.path().extension()))
            file_urls.emplace_back(fs::u8path(p));
    }
    return file_urls;
}

void MainProcess::sendGpsToTxt(const std::vector<std::string>& file_urls)
{
    double lat = 0, lon = 0, alt = 0;

    std::ofstream txt;
    txt.open("gps_coordinates.txt");
    
    if (!file_urls.empty())
        for (auto &file : file_urls)
        {
            retrieveGpsCoordinate(file, lat, lon, alt);
            if (lat != 0.0 && lon != 0.0)
            {
                txt << lat << " " << lon << " " << alt << "\n";
            }
        }
    else
    {
        std::cout << "No matching files was found" << '\n'; // or "*were found"
    }
    txt.close();
}

void MainProcess::retrieveGpsCoordinate(const std::string& file_name, double &lat, double &lon, double &alt)
{
    FILE *fp = fopen(file_name.c_str(), "rb");
    if (!fp)
    {
        std::cout << "Sorry. I can't parse this file type yet" << '\n';
    }
    fseek(fp, 0, SEEK_END);
    unsigned long fsize = ftell(fp);
    rewind(fp);
    auto *buf = new unsigned char[fsize];
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