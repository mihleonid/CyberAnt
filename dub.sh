#!/bin/bash
echo "Your file (without cpp):";
n="build"
b="$(basename -- $n)"
g++ -g "$n.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -g -o "$b" "$b.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "$b.o"
gdb "./$b"

