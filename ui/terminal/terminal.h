#pragma once
#include <iostream>

#ifndef ESC
#define ESC "\033"
#endif

#define T_HOME() printf(ESC "[H")
#define T_CLEAR() printf(ESC "[2J")
#define T_GOTO(x,y) printf(ESC "[%d;%dH", y, x);
#define T_OPT(color) printf(ESC "[%dm",color)
#define T_NL() T_OPT(O_RESET);printf("\n")

//Format text
#define O_RESET 0
#define O_BOLD 1
#define O_DIM 2
#define O_UNDERLINE 3
#define O_BLINK 4
#define O_REVERSE 5
#define O_HIDDEN 6
#define O_INVERTED 7 //test
//Foreground
#define F_BLACK 30
#define F_RED 31
#define F_GREEN 32
#define F_YELLOW 33
#define F_BLUE 34
#define F_MAGENTA 35
#define F_CYAN 36
#define F_WHITE 37
//Background
#define B_BLACK 40
#define B_RED 41
#define B_GREEN 42
#define B_YELLOW 44
#define B_BLUE 44
#define B_MAGENTA 45
#define B_CYAN 46
#define B_WHITE 47
