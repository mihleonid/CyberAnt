#!/bin/bash

bash pretest.sh

g++ -Ofast "main.cpp" -c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
g++ -Ofast -o "main" "main.o" `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lpthread
rm "main.o"
rm "main.cpp"
./main
rm "main"

echo "Done"

