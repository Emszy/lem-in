RED="\033[31m";
GREEN="\033[32m";
DEFAULT="\033[37m";

echo "\033[32m"
./lem-in tests/lem-in_maps/*.map
./lem-in tests/lem-in_maps/big_maps/map20k-m
./lem-in tests/lem-in_maps/big_maps/map200k-m
./lem-in tests/lem-in_maps/big_maps/map50k-m