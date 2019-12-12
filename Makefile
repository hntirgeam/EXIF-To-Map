CC=g++
FLAGS=-std=c++17 -lstdc++fs
FILES=main.cpp mainprocess.cpp exif.cpp

all: 
	$(CC) $(FILES)  $(FLAGS)

clean:
	rm *.html *.out *.txt 