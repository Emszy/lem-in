RED="\033[31m";
GREEN="\033[32m";
DEFAULT="\033[37m";

echo "\033[32m"


echo "\n\ntest.txt\n"
./lem-in test.txt
echo "\ntest1.txt\n"
./lem-in test1.txt
echo "\ntest2.txt\n"
./lem-in test2.txt
echo "\ntests/1.map\n"
./lem-in tests/1.map
echo "\ntests/10k.map\n"
echo "THIS MIGHT TAKE A SEC\n\n"
# ./lem-in tests/10k.map
echo "\ntests/10_lots_of_comments.map\n"
./lem-in tests/10_lots_of_comments.map
echo "\ntests/9_path_depth_4_ants.map\n"
./lem-in tests/9_path_depth_4_ants.map
echo "\ntests/9_path_depth_8_ants.map\n"
./lem-in tests/9_path_depth_8_ants.map
echo "\ntests/20.map\n"
./lem-in tests/20.map
echo "\ntests/5.map\n"
./lem-in tests/5.map
echo "\ntests/1.map\n"
./lem-in tests/1.map
echo "\ntests/9_path_depth_2_ants.map\n"
./lem-in tests/9_path_depth_2_ants.map
echo "\ntests/10.map\n"_depth_2_ants.map
./lem-in tests/10.map
echo "\ntests/9_path_depth_9_ants.map\n"
./lem-in tests/9_path_depth_9_ants.map
echo "\ntests/10_lots_of_comments.map\n"
./lem-in tests/2.map
echo "\ntests/9_path_depth_10_ants.map\n"
./lem-in tests/9_path_depth_10_ants.map
echo "\ntests/9_path_depth_1_ants.map \n"
./lem-in tests/9_path_depth_1_ants.map 

echo "\n\033[31m"

echo "\ntests/err_no_ants2.map\n\n"
./lem-in tests/err_no_ants2.map
echo "\ntests/err_no_links.map \n\n"
./lem-in tests/err_no_links.map 
echo "\ntests/err_no_ants.map\n\n"
./lem-in tests/err_no_ants.map
echo "\ntests/err_no_start.map\n\n"
./lem-in tests/err_no_start.map
echo "\ntests/err_no_start2.map\n\n"
./lem-in tests/err_no_start2.map
echo "\ntests/err_start_end_same.map\n\n"
./lem-in tests/err_start_end_same.map
echo "\ntests/err_too_few_ants.map\n\n"
./lem-in tests/err_too_few_ants.map
echo "\ntests/err_too_many_ants.map\n\n"
./lem-in tests/err_too_many_ants.map
echo "\ntests/err_no_ants2.map\n\n"
./lem-in tests/err_no_ants2.map
echo "\ntests/err_no_ants3.map \n\n"
./lem-in tests/err_no_ants3.map 
echo "\ntests/err_no_end.map\n\n"
./lem-in tests/err_no_end.map
echo "\ntests/err_no_end2.map\n\n"
./lem-in tests/err_no_end2.map
echo "\ntests/err_3_coordinates.map\n\n"
./lem-in tests/err_3_coordinates.map
echo "\ntests/err_no_links.map\n\n"
./lem-in tests/err_no_links.map
echo "\ntests/err_no_path.map\n\n"
./lem-in tests/err_no_path.map
echo "\ntests/err_empty.map\n\n"
./lem-in tests/err_empty.map
echo "\ntests/err_no_rooms.map\n\n"
./lem-in tests/err_no_rooms.map
echo "\ntests/err_letter_in_coordinate.map\n\n"
./lem-in tests/err_letter_in_coordinate.map
echo "\ntests/err_link_to_unknown_room.map\n\n"
./lem-in tests/err_link_to_unknown_room.map
