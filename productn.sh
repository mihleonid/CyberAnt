#!/bin/bash
echo "Compiling for production (no SDL): build";
n="build"
b="$(basename -- $n)"
g++ -O3 -Ofast "$n.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -O3 -Ofast -o "$b" "$b.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "$b.o"
"./$b"

