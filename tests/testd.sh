#!/bin/bash

g++ tester.cpp
mv a.out tester
for file in tests/*.cpp;
	do
		./tester $file
		cat tmp1.txt>>atop.txt
		cat tmp2.txt>>amiddle.txt
		rm tmp1.txt tmp2.txt
	done
rm tester
cat top.txt>main.cpp
cat atop.txt>>main.cpp
cat middle.txt>>main.cpp
cat amiddle.txt>>main.cpp
cat bottom.txt>>main.cpp
rm "atop.txt"
rm "amiddle.txt"

g++ -g -ggdb "main.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -g -ggdb -o "main" "main.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "main.o"
rm "main.cpp"
gdb main
rm "main"


echo "Done"

