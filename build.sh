rm -Rf build 2>/dev/null;
mkdir build;
cmake -Bbuild -S.;
make -C build;
mv build/gps_to_mapCPP .;

echo ;
echo Usage: ./gps_to_mapCPP or ./gps_to_mapCPP [path to photo dirrectory]
