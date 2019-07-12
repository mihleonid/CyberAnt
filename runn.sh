#!/bin/bash
echo "Running without sdl: "
n="build"
b="$(basename -- $n)"
g++ -D_GLIBCXX_DEBUG -DDEBUG "$n.cpp" -c -lpthread
g++ -D_GLIBCXX_DEBUG -DDEBUG -o "$b" "$b.o" -lpthread
rm "$b.o"
"./$b"

