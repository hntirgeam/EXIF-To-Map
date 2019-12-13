# EXIF To Map
* Simple C++ programm with Python script that will help you create map with markers on it, by checking all you *.jpeg files for EXIF instancies

## Setup
* Simply `make` and `./a.out` (you can also pass folder/directory as argv) programm. Follow the instructions. After C++ part run `python3 map.py` (you will also need to `pip3 install folium` for python script to run). It'll generate two `.html` files with map (one with standard map and one with heatmap). Open it in your browser and explore the map. 

## Screenshots
* Map will look like this:
![example](https://user-images.githubusercontent.com/56179857/70716983-75b09880-1cfe-11ea-9009-ebb0e7be94ec.png)

## To-do:
* Investigate about parsing `.raw` and `.dng` files. 
