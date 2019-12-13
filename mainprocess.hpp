#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <experimental/filesystem>


class MainProcess
{

public:
    
    std::vector<std::string> getPath(const std::string &dirPath);

    void retrieveGpsCoordinate(std::string file_name, double &lat, double &lon, double &alt);

    void sendGpsToTxt(const std::vector<std::string> &file_name);
};