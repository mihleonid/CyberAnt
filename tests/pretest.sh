#!/bin/bash

bash generatebuild.sh;
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

