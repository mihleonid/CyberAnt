# CyberAnt

## Compiling
1. Copy project and assets dir.
2. Build it:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2.1. For linux: install cmake and all dependencies (SDL).
```sh
	cd <projdir>
	mkdir build && cd build && cmake ..
```
   Make a link in build dir to assets:
```sh
	ln -s ../assets assets
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 2.2. For windows: install cmake and all dependencies (SDL) (libsdl.org).
```bat
	cd <projdir>
	mkdir build
	cd build
	cmake ..
```
   Copy assets to build dir:
```bat
	xcopy ..\assets\ assets\
```
   We do not know is this application suitable for windows.
3. Compile the project:
```sh
	make
```

## Alternative run (Linux only)
1. Copy project and assets dir.
2. Run:
```sh
	bash *.sh
```
   Where `*`.sh can be:
	  dub.sh - debug with gdb.
	  run.sh - run.
	  runn.sh - run with no sdl.
	  rune.sh - run with stderr to less.
	  product.sh - run with -03 -0fast without debug macros.
	  productn.sh - run with -03 -0fast without debug macros without sdl.

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

