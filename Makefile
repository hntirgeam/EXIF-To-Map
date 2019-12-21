CC=g++
FLAGS=-std=c++17 -lstdc++fs  -O3
FILES=main.cpp mainprocess.cpp exif.cpp
NAME=GpsToMap

all: 
	$(CC) $(FILES)  $(FLAGS) -o $(NAME)

clean:
	rm *.html *.out *.txt 