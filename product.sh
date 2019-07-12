#!/bin/bash
echo "Compiling for production: build";
n="build"
b="$(basename -- $n)"
g++ -O3 -Ofast -DSDL "$n.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -O3 -Ofast -DSDL -o "$b" "$b.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "$b.o"
"./$b"

