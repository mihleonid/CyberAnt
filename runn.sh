#!/bin/bash
echo "Your file (without cpp):";
n="build"
b="$(basename -- $n)"
g++ "$n.cpp" -c -lpthread
g++ -o "$b" "$b.o" -lpthread
rm "$b.o"
"./$b"

