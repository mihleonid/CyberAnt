#!/bin/bash

bash pretest.sh

g++ -g -ggdb "main.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -g -ggdb -o "main" "main.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "main.o"
rm "main.cpp"
gdb main
rm "main"


echo "Done"

