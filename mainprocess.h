#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <experimental/filesystem>

class MainProcess
{
private:

    double m_latitude;
    double m_longitude;
    double m_altitude;

public:

    void setCoordinates(double &latitude, double &longitude, double &altitude)
    {
        m_latitude = latitude;
        m_longitude = longitude;
        m_altitude = altitude;
    }
    std::string getPath(const std::string dirPath);

    void retrieveGpsCoordinate(const std::string file_path, double &lat, double &lon, double &alt);

    void sendGpsToTxt(const std::string file_name, double *lat, double *lon, double *alt);

    void printToConsole();
};

#endif