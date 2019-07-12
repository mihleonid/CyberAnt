#!/bin/bash
echo "Bebug for: build";
n="build"
b="$(basename -- $n)"
g++ -D_GLIBCXX_DEBUG -DDEBUG -DSDL -g -ggdb "$n.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -D_GLIBCXX_DEBUG -DDEBUG -DSDL -g -ggdb -o "$b" "$b.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "$b.o"
gdb "./$b"

