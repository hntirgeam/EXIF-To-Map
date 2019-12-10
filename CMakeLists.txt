cmake_minimum_required(VERSION 3.14)
project(gps_to_mapCPP)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 17)
link_libraries(stdc++fs)
include_directories(.)

add_executable(gps_to_mapCPP
        exif.cpp
        exif.hpp
        Main.cpp
        MainProcess.cpp
        MainProcess.hpp)
