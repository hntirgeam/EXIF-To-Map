import folium


m = folium.Map(location=[47.963, 24.055], tiles="OpenStreetMap", zoom_start=4)


def create_markers():
    try:
        readfile = open("gps_coordinates.txt", "r")
        readfile_split = readfile.read().splitlines()
        i = 0
        while i < len(readfile_split):
            latitude, longitude, altitude = readfile_split[i].split(' ')
            i += 1
            folium.Marker([latitude, longitude]).add_to(m)
        m.save('map.html')
    finally:
        readfile.close()


create_markers()
