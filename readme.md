# CyberAnt

## Compiling
1. copy project and assets dir
2. build
   2. 1. for linux: install cmake and all dependencies (SDL)
```sh
	cd <projdir>
	mkdir build && cd build && cmake ..
```
   make a link in build dir to assets:
```sh
	ln -s ../assets assets
```
   2. 2. for windows: install cmake and all dependencies (SDL) (libsdl.org)
```bat
	cd <projdir>
	mkdir build
	cd build
	cmake ..
```
   copy assets to build dir:
```sh
	xcopy ..\assets\ assets\
```
   We do not know is this application suitable for windows.
3. Compile the project:
```sh
	make
```

## Overview
HiberAnt is the best game of all.
There is a big field. You can place buildings on it. Build base, mines, attack buildings. Protect your base and fight against other players and enemies.
There are 18 levels of buildings.

## Controls
	<Left> Slow left scrolling
	<Right> Slow right scrolling
	<Up> Slow up scrolling
	<Down> Slow down scrolling
	<Esc> Exit
	w, a, s, d - scrolling
	^w, ^a, ^s, ^d - fast scrolling
	W, A, S, D - fast scrolling
	^W, ^A, ^S, ^D - very fast scrolling

	Mouse drag and move - scrolling
	Mouse down and up without movement - click


	xcopy ..\assets\ assets\
   we do not know is this application suitable for windows
3) Compile the project:
	make

## Overview
HiberAnt is the best game of all.
There is a big field. You can place buildings on it. Build base, mines, attack buildings. Protect your base and fight against other players and enemies.
There are 18 levels of buildings.

## Controls
	<Left> Slow left scrolling
	<Right> Slow right scrolling
	<Up> Slow up scrolling
	<Down> Slow down scrolling
	<Esc> Exit
	w, a, s, d - scrolling
	^w, ^a, ^s, ^d - fast scrolling
	W, A, S, D - fast scrolling
	^W, ^A, ^S, ^D - very fast scrolling

	Mouse drag and move - scrolling
	Mouse down and up without movement - click

