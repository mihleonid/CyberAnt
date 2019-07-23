# CyberAnt

## Compiling
1. Copy project and assets dir
2. Build

	2.1. For linux:
	- install cmake and all dependencies (SDL):
	```sh
		cd <projdir>
		mkdir build && cd build && cmake ../src
	```
	- Make a link in build dir to assets:
	```sh
		ln -s ../assets assets
	```
	2.2. For windows:
	- install cmake and all dependencies (SDL) (libsdl.org):
	```bat
		cd <projdir>
		mkdir build
		cd build
		cmake ../src
	```
	- copy assets to build dir:
	```sh
		xcopy ..\assets\ assets\
	```
	*This application can be not suitable for windows.*
3. Compile the project:
```sh
	make
```

## Overview
HiberAnt is the best game of all.
There is a big field. You can place buildings on it. Build base, mines, attack buildings. Protect your base and fight against other players and enemies.
There are 18 levels of buildings.

## Controls
	<Left> Slow left camera scrolling
	<Right> Slow right camera scrolling
	<Up> Slow up camera scrolling
	<Down> Slow down camera scrolling
	<Esc> Exit
	w, a, s, d - scrolling
	^w, ^a, ^s, ^d - fast scrolling
	W, A, S, D - fast scrolling
	^W, ^A, ^S, ^D - very fast scrolling

	Mouse drag - scrolling
	Mouse clicked without movement - click
