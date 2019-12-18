# EXIF To Map
* Simple C++ program with Python script that will help you create map with markers on it, by checking all your *.jpeg files for EXIF instancies

## Setup
* Simply `make` and `./a.out` (you can also pass folder/directory as argv) programm. Follow the instructions. Run `python3 map.py` after C++ part (you will also need to `pip3 install folium` for python script to run). It will generate two `.html` files with map (one with standard map and the other with heatmap). Open it in your browser and explore the map. 

## Screenshots
* ### Map will look like this:
![example2](https://user-images.githubusercontent.com/56179857/70820424-b3d6b680-1de9-11ea-9da5-afc15f1b2501.jpg)

* ### Heatmap will look like this:
![example1](https://user-images.githubusercontent.com/56179857/70820369-8e49ad00-1de9-11ea-82ee-a10ad4649b91.jpg)

## To-do:
* Investigate about parsing `.raw` and `.dng` files. 
