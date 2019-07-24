#!/bin/bash

echo "Generating build file..."
cat buildtop.txt > build.cpp
find ../src |grep "\.cpp"|grep -v "Make"|grep -v "main.cpp"|sed "i\#include["|xargs -n 2 echo|sed "s/ //"|sed "a]"|xargs -n 2 echo|sed "s/ //"|sed "s/\[/ \"/"|sed "s/\]/\"/"|sort >>build.cpp
echo "Generated"

