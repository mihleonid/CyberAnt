#pragma once
#include "point.h"
#ifdef _WIN32
#include <windows.h>
Point terminal_size(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns=csbi.srWindow.Right-csbi.srWindow.Left+1;
    rows=csbi.srWindow.Bottom-csbi.srWindow.Top+1;
    return Point(colums, rows);
}
#elif _WIN64
#include <windows.h>
Point terminal_size(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns=csbi.srWindow.Right-csbi.srWindow.Left+1;
    rows=csbi.srWindow.Bottom-csbi.srWindow.Top+1;
    return Point(colums, rows);
}
#else
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
Point treminal_size(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return Point(w.ws_col, w.ws_row);
}
#endif

