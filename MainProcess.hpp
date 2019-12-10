#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <experimental/filesystem>
#include "exif.hpp"
#include <cstdio>
#include <ctime>

class MainProcess
{

public:
    
    std::vector<std::string> getPath(const std::string& dirPath);

    void retrieveGpsCoordinate(const std::string& file_name, double &lat, double &lon, double &alt);

    void sendGpsToTxt(const std::vector<std::string>& file_name);
};